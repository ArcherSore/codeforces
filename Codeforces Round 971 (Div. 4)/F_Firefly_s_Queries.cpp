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
    LL n, q;
    cin >> n >> q;

    vector<LL> v(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    while (q--) {
        LL l, r;
        cin >> l >> r;
        LL p1 = (l - 1) / n + 1, p2 = (r - 1) / n + 1;
        LL r1 = (l - 1) % n, r2 = (r - 1) % n;

        LL ans = 0;
        if (p1 == p2) {
            LL st = (p1 + r1) % n == 0 ? n : (p1 + r1) % n;
            LL ed = (p2 + r2) % n == 0 ? n : (p2 + r2) % n;
            if (st <= ed) {
                ans = sum[ed] - sum[st - 1];
            } else {
                ans = (sum[n] - sum[st - 1]) + (sum[ed] - sum[0]);
            }
        } else {
            ans = (p2 - p1 - 1) * sum[n];

            LL st = (p1 + r1) % n == 0 ? n : (p1 + r1) % n;
            LL ed = (p1 + n - 1) % n == 0 ? n : (p1 + n - 1) % n;
            if (st <= ed) {
                ans += sum[ed] - sum[st - 1];
            } else {
                ans += (sum[n] - sum[st - 1]) + (sum[ed] - sum[0]);
            }

            st = p2;
            ed = (p2 + r2) % n == 0 ? n : (p2 + r2) % n;
            if (st <= ed) {
                ans += sum[ed] - sum[st - 1];
            } else {
                ans += (sum[n] - sum[st - 1]) + (sum[ed] - sum[0]);
            }
        }
        cout << ans << '\n';
    }
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