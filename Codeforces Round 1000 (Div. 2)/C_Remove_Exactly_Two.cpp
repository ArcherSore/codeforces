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

struct Ver {
    int u, deg;
    vector<int> e;
    Ver() : u(-1), deg(0) {}
    bool operator<(const Ver &other) const {
        return deg > other.deg;
    }
    bool is_adj(int v) {
        auto it = lower_bound(e.begin(), e.end(), v);
        if (it != e.end() && (*it) == v) {
            return true;
        }
        return false;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<Ver> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].e.push_back(v);
        g[u].deg++;
        g[v].e.push_back(u);
        g[v].deg++;
    }
    for (int i = 0; i < n; i++) {
        g[i].u = i;
        sort(g[i].e.begin(), g[i].e.end());
    }
    sort(g.begin(), g.end());

    int max_deg = g[0].deg, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (g[i].deg != max_deg) {
            break;
        }
        cnt++;   
    }

    if (cnt == 1) {
        int res = g[0].deg + g[1].deg - 2, u = g[0].u;
        max_deg = g[1].deg;
        for (int i = 1; i < n; i++) {
            if (g[i].deg != max_deg) {
                break;
            }
            if (!g[0].is_adj(g[i].u)) {
                res += 1;
                cout << res << '\n';
                return;
            }
        }
        cout << res << '\n';
    } else {
        int res = 2 * max_deg - 2;
        for (int i = 0; i < cnt; i++) {
            for (int j = i + 1; j < cnt; j++) {
                if (!g[i].is_adj(g[j].u)) {
                    res += 1;
                    cout << res << '\n';
                    return;
                }
            }
        }
        cout << res << '\n';
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