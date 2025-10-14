#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for (auto &s : g) {
        cin >> s;
    }
    vector<vector<int>> vis(n, vector<int> (m));
    vector<int> px[2], py[2];
    auto bfs = [&](int i, int j, int lvl) -> void {
        queue<pii> q;
        q.push({i, j});
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (vis[x][y]) {
                continue;
            }
            vis[x][y] = 1;
            px[lvl].push_back(x);
            py[lvl].push_back(y);
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] || g[nx][ny] == '#') {
                    continue;
                }
                q.push({nx, ny});
            }
        }
    };
    bfs(0, 0, 0);
    if (vis[n - 1][m - 1]) {
        cout << 0 << '\n';
        return;
    }
    bfs(n - 1, m - 1, 1);

    vector<vector<int>> dist(n, vector<int> (m, -inf));
    queue<pii> q;
    for (int i = 0; i < px[0].size(); i++) {
        int x = px[0][i], y = py[0][i];
        dist[x][y] = 0;
        q.push({x, y});
    }
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || dist[nx][ny] != -inf) {
                continue;
            }
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    int res = inf;
    for (int i = 0; i < px[1].size(); i++) {
        int x = px[1][i], y = py[1][i];
        res = min(res, dist[x][y] - 1);
    }
    cout << res << '\n';
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

// 1:54:16