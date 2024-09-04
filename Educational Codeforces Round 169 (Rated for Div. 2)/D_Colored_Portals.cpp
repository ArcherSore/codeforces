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
    int n, q;
    cin >> n >> q;

    vector<string> v(n + 1);
    map<string, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (v[i][0] > v[i][1]) {
            swap(v[i][0], v[i][1]);
        }
        mp[v[i]].push_back(i);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            swap(a, b);
        }
        string s, t;
        s = v[a], t = v[b];

        int ans = 1e9;
        for (char c : s) {
            for (char cc : t) {
                string ss;
                ss.push_back(min(c, cc));
                ss.push_back(max(c, cc));
                if (mp.find(ss) == mp.end()) {
                    continue;
                }
                // check wheter vector `mp[ss]` has numbers in (a, b)
                auto it_a = lower_bound(mp[ss].begin(), mp[ss].end(), a + 1);
                if (it_a != mp[ss].end() && *it_a < b) {
                    ans = min(ans, b - a);
                } else {
                    if (it_a != mp[ss].begin()) {
                        int max_bef_a = *(--it_a);
                        ans = min(ans, a + b - 2 * max_bef_a);
                    }
                    auto it_b = lower_bound(mp[ss].begin(), mp[ss].end(), b);
                    if (it_b != mp[ss].end()) {
                        int min_aft_b = *it_b;
                        ans = min(ans, 2 * min_aft_b - a - b);
                    }
                }
            }
        }
        if (ans == 1e9) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
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