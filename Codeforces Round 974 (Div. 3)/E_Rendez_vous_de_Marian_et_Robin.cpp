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

struct Status {
    LL dis;
    int u, h;
    bool operator<(const Status &other) const {
        return dis > other.dis;
    }
};

vector<LL> dijkstra(int s, const vector<int> &horse, const vector<vector<PLI>> &G) {
    int n = horse.size();
    vector<vector<int>> vis(n, vector<int> (2));
    vector<vector<LL>> dis(n, vector<LL> (2, INF));
    vector<LL> ans(n);
    priority_queue<Status> pq;
    pq.push({0LL, s, horse[s]});
    dis[s][horse[s]] = 0;
    
    while (!pq.empty()) {
        auto [d, x, h] = pq.top();
        pq.pop();
        if (vis[x][h]) {
            continue;
        }
        vis[x][h] = 1;
        
        for (auto [w, y] : G[x]) {
            // 如果该状态是'骑马'
            if (h) {
                if (dis[x][1] + w / 2 < dis[y][1]) {
                    dis[y][1] = dis[x][1] + w / 2;
                    pq.push({dis[y][1], y, 1});
                }
                // if (dis[x][1] + w / 2 < dis[y][0]) {
                //     dis[y][0] = dis[x][1] + w;
                //     pq.push({dis[y][1], y, 0});
                // }
            } else {
                if (dis[x][0] + w < dis[y][horse[y]]) {
                    dis[y][horse[y]] = dis[x][0] + w;
                    pq.push({dis[y][horse[y]], y, horse[y]});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        ans[i] = min(dis[i][0], dis[i][1]);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << ' ';
    // }
    // cout << '\n';

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
    
    vector<vector<PLI>> G(n);  
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        G[u].push_back({w, v});
        G[v].push_back({w, u});
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