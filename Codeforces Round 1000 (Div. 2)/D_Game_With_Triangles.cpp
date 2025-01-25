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
    int n, m;
    cin >> n >> m;
    vector<LL> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int opt;
    if (max(n, m) >= 2 * min(n, m)) {
        opt = min(n, m); 
    } else {
        opt = (n + m) / 3;
    }
    cout << opt << '\n';

    int l1 = 0, r1 = n - 1;
    int l2 = 0, r2 = m - 1;
    int rest1 = n, rest2 = m;

    int flag = 0;
    LL res = 0;
    vector<PII> v1, v2;
    for (int i = 1; i <= opt; i++) {
        if (rest1 >= 2 && rest2 >= 2) {
            if (a[r1] - a[l1] >= b[r2] - b[l2]) {
                res += a[r1] - a[l1];
                v1.push_back({l1, r1});
                l1++, r1--;
                rest1 -= 2, rest2 -= 1;
            } else {
                res += b[r2] - b[l2];
                v2.push_back({l2, r2});
                l2++, r2--;
                rest1 -= 1, rest2 -= 2;
            }
            cout << res << ' ';
            continue;
        }

        if (rest1 == 1) {
            res += b[r2] - b[l2];
            v2.push_back({l2, r2});
            l2++, r2--;
            rest1 -= 1, rest2 -= 2;

            cout << res << ' ';
            continue;
        }
        if (rest2 == 1) {
            res += a[r1] - a[l1];
            v1.push_back({l1, r1});
            l1++, r1--;
            rest1 -= 2, rest2 -= 1;

            cout << res << ' ';
            continue;
        }

        if (rest1 == 0) {
            auto [tl, tr] = v1.back();
            v1.pop_back();
            res -= a[tr] - a[tl];
            l1--, r1++;
            rest1 += 2, rest2 += 1;
            
            res += b[r2] - b[l2];
            v2.push_back({l2, r2});
            l2++, r2--;
            rest1 -= 1, rest2 -= 2;

            res += b[r2] - b[l2];
            v2.push_back({l2, r2});
            l2++, r2--;
            rest1 -= 1, rest2 -= 2;

            cout << res << ' ';
            continue;
        }
        if (rest2 == 0) {
            auto [tl, tr] = v2.back();
            v2.pop_back();
            res -= b[tr] - b[tl];
            l2--, r2++;
            rest1 += 1, rest2 += 2;

            res += a[r1] - a[l1];
            v1.push_back({l1, r1});
            l1++, r1--;
            rest1 -= 2, rest2 -= 1;

            res += a[r1] - a[l1];
            v1.push_back({l1, r1});
            l1++, r1--;
            rest1 -= 2, rest2 -= 1;

            cout << res << ' ';
            continue;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}