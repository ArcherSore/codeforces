// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;

void solve() {
    LL n, x, y;
    cin >> n >> x >> y;
    vector<LL> a(n);
    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(), a.end());

    LL l = sum - y; 
    LL r = sum - x;

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL ll = l - a[i];
        LL rr = r - a[i];

        auto it1 = lower_bound(a.begin() + i + 1, a.end(), ll);
        auto it2 = upper_bound(a.begin() + i + 1, a.end(), rr);

        ans += (it2 - it1);
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}