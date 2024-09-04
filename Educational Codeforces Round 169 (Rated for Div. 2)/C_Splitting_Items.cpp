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
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v.emplace_back(x);
    }
    sort(v.begin(), v.end(), greater<> ());

    int ans = 0;
    if (n % 2) {
        ans = v.back();
        v.pop_back();
        n -= 1;
    }
    
    int tot = 0;
    for (int i = 0; i < n; i += 2) {
        tot += v[i] - v[i + 1];
    }
    ans += max(0, tot - k);

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