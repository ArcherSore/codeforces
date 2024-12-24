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
    vector<LL> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<LL> p;
    for (int i = 0; i < n; i++) {
        p.push_back(a[i]);
        p.push_back(b[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    LL ans = 0;
    for (auto x : p) {
        int pb = lower_bound(b.begin(), b.end(), x) - b.begin();
        LL buy = n - pb;
        int pa = lower_bound(a.begin(), a.end(), x) - a.begin();
        LL pos = n - pa;

        LL neg = buy - pos;

        if (neg <= k && buy > 0) {
            ans = max(ans, x * buy);
        }
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