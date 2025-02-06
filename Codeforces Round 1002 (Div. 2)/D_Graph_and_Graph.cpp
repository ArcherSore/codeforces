#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

struct State {
    int cost;
    int u, v;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    s1--, s2--;
    vector<vector<int>> g1(n), g2(n);
    vector<vector<int>> G1(n, vector<int> (n));
    vector<vector<int>> G2(n, vector<int> (n));
    int m1, m2;
    cin >> m1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g1[u].push_back(v);
        g1[v].push_back(u);
        G1[u][v] = G1[v][u] = 1;
    }
    cin >> m2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g2[u].push_back(v);
        g2[v].push_back(u);
        G2[u][v] = G2[v][u] = 1;
    }

    vector<int> good(n);
    for (int u = 0; u < n; u++) {
        for (int v : g1[u]) {
            if (G2[u][v]) {
                good[u] = 1;
                break;
            }
        }
    }

    auto dijkstra = [&]() -> void {
        vector<vector<int>> vis(n, vector<int> (n));
        vector<vector<int>> dist(n, vector<int> (n, INF));
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[s1][s2] = 0;
        pq.push({0, s1, s2});

        while (!pq.empty()) {
            auto [d, u, v] = pq.top();
            pq.pop();
            if (vis[u][v]) {
                continue;
            }
            vis[u][v] = 1;

            for (auto nu : g1[u]) {
                for (auto nv : g2[v]) {
                    int nd = d + abs(nu - nv);
                    if (dist[u][v] + abs(nu - nv) < dist[nu][nv]) {
                        dist[nu][nv] = dist[u][v] + abs(nu - nv);
                        pq.push({dist[nu][nv], nu, nv});
                    }
                }
            }
        }

        int ans = INF;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < ans && good[i]) {
                ans = dist[i][i];
            }
        }
        cout << (ans == INF ? -1 : ans) << '\n';
    };
    dijkstra();
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