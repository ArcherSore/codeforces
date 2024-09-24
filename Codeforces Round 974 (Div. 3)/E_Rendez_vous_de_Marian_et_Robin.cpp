// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;
using LL = long long;
using PLI = pair<LL, int>;
const LL INF = 1e18;

vector<LL> dijkstra(int s, const vector<int> &horse, const vector<vector<PLI>> &G) {
    int n = horse.size();
    vector<int> vis(2 * n);
    vector<LL> dis(2 * n, INF);
    priority_queue<PLI, vector<PLI>, greater<>> pq;
    if (horse[s]) {
        pq.push({0LL, s + n});
        dis[s + n] = 0;
    } else {
        pq.push({0LL, s});
        dis[s] = 0;
    }
    
    while (!pq.empty()) {
        auto [d, x] = pq.top();
        pq.pop();
        if (vis[x]) {
            continue;
        }
        vis[x] = 1;
        
        for (auto [w, y] : G[x]) {
            if (dis[x] + w < dis[y]) {
                dis[y] = dis[x] + w;
                pq.push({dis[y], y});
            }
        }
    }

    vector<LL> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = min(dis[i], dis[i + n]);
    }
    return ans;
}

void solve() {
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> horse(n, 0);  
    for (int i = 0; i < h; i++) {
        int x;
        cin >> x;
        horse[x - 1] = 1;
    }
    
    vector<vector<PLI>> G(2 * n);
    vector<int> vis(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
        G[u + n].push_back({w / 2, v + n});
        G[v + n].push_back({w / 2, u + n});

        if (horse[u] && !vis[u]) {
            vis[u] = 1;
            G[u].push_back({0, u + n});
            G[u + n].push_back({0, u});
        }
        if (horse[v] && !vis[v]) {
            vis[v] = 1;
            G[v].push_back({0, v + n});
            G[v + n].push_back({0, v});
        }
    }
    
    vector<LL> distM = dijkstra(0, horse, G); 
    vector<LL> distR = dijkstra(n - 1, horse, G);  

    LL ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, max(distM[i], distR[i]));
    }

    if (ans == INF) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}