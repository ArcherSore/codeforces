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

int n, m;
struct Road {
    int v, bus, walk;
};

bool check(vector<vector<Road>> &G, int t0, int t1, int t2) {
    vector<int> vis(n + 1);
    vector<int> dis(n + 1, 0x3f3f3f3f);
    dis[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto [t, x] = q.top();
        q.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;

        for (auto [y, bus, walk] : G[x]) {
            if (t2 <= t || t + bus <= t1) {
                // take a bus
                if (dis[x] + bus < dis[y]) {
                    dis[y] = dis[x] + bus;
                    q.push({dis[y], y});
                }
            } else {
                // choose to walk or stay
                if (t2 + bus < dis[x] + walk && t2 + bus < dis[y]) {
                    dis[y] = t2 + bus;
                    q.push({dis[y], y});
                }
                if (dis[x] + walk <= t2 + bus && dis[x] + walk < dis[y]) {
                    dis[y] = dis[x] + walk;
                    q.push({dis[y], y});
                }
            }
        }
    }
    // cout << "minimum time = " << dis[n - 1] << "\n\n";
    return dis[n - 1] <= t0;
}

void solve() {
    int t0, t1, t2;
    cin >> n >> m >> t0 >> t1 >> t2;
    vector<vector<Road>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v, bus, walk;
        cin >> u >> v >> bus >> walk;
        u--, v--;
        G[u].push_back({v, bus, walk});
        G[v].push_back({u, bus, walk});
    }

    int l = -1, r = t0, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        // cout << "start = " << mid << '\n';
        if (check(G, t0 - mid, t1 - mid, t2 - mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
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