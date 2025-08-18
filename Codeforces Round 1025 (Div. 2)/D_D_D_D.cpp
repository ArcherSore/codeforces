#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;
const int N = 2e5;

const int INF = 2e9 + 1;

struct State {
    int u, parity;
    int dist;
    bool operator>(const State &other) const {
        return dist > other.dist;
    }
};

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    int sum = 0, min_odd = INF;
    vector<int> a(l);
    for (auto &x : a) {
        cin >> x;
        sum += x;
        if (x & 1) {
            min_odd = min(min_odd, x);
        }
    }
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int even_dist = -1, odd_dist = -1;
    if (min_odd == INF) {
        even_dist = sum;
    } else {
        even_dist = odd_dist = sum;
        if (odd_dist & 1) {
            even_dist -= min_odd;
        } else {
            odd_dist -= min_odd;
        }
    }

    vector<vector<int>> dist(n, vector<int> (2, INF));
    vector<vector<int>> vis(n, vector<int> (2));
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 0});
    dist[0][0] = 0;
    while (!pq.empty()) {
        auto [u, p, d] = pq.top();
        pq.pop();
        if (vis[u][p]) {
            continue;
        }
        vis[u][p] = 1;

        for (int v : adj[u]) {
            int tp = 1 - p;
            if (dist[u][p] + 1 < dist[v][tp]) {
                dist[v][tp] = dist[u][p] + 1;
                pq.push({v, tp, dist[v][tp]});
            }
        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (dist[i][0] <= even_dist || dist[i][1] <= odd_dist) {
            res[i] = 1;
        }
    }
    for (auto x : res) {
        cout << x;
    }
    cout << '\n';
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