#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

vector<int> kx = {-2, -2, -1, 1, 2, 2, 1, -1};
vector<int> ky = {-1, 1, 2, 2, 1, -1, -2, -2};

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int> (n));
    vector<int> pos(n * n + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            pos[g[i][j]] = i * n + j;
        }
    }

    // precalculate the minimum steps it takes to reach any (x, y) from (i, j) with 3 pieces
    const int V = 3 * n * n;
    vector<vector<PII>> dist(V, vector<PII> (V, {INF, INF})); // {step, changing cost}
    for (int i = 0; i < V; i++) {
        dist[i][i] = {0, 0};
    }
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int base = x * n + y;
            for (int s = 0; s < 3; s++) {
                int u = s * n * n + base;
                // change the current piece
                for (int t = 0; t < 3; t++) {
                    if (s == t) {
                        continue;
                    }
                    int v = t * n * n + base;
                    dist[u][v] = min(dist[u][v], {1, 1});
                }
                // don't change
                if (s == 0) {
                    // knight
                    for (int d = 0; d < 8; d++) {
                        int nx = x + kx[d], ny = y + ky[d];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
                            continue;
                        } 
                        int v = s * n * n + nx * n + ny;
                        dist[u][v] = min(dist[u][v], {1, 0});
                    }
                } else if (s == 1) {
                    // bishop
                    int dx[4] = {1, 1, -1, -1};
                    int dy[4] = {1, -1, 1, -1};
                    for (int d = 0; d < 4; d++) {
                        for (int nx = x + dx[d], ny = y + dy[d]; nx >= 0 && nx < n && ny >= 0 && ny < n; nx += dx[d], ny += dy[d]) {
                            int v = s * n * n + nx * n + ny;
                            dist[u][v] = min(dist[u][v], {1, 0});
                        }
                    }
                } else {
                    // rook
                    int dx[4] = {1, -1, 0, 0};
                    int dy[4] = {0, 0, 1, -1};
                    for (int d = 0; d < 4; d++) {
                        for (int nx = x + dx[d], ny = y + dy[d]; nx >= 0 && nx < n && ny >= 0 && ny < n; nx += dx[d], ny += dy[d]) {
                            int v = s * n * n + nx * n + ny;
                            dist[u][v] = min(dist[u][v], {1, 0});
                        }
                    }
                }
            }
        }
    }

    // shortest path, i->k->j
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            if (dist[i][k].first == INF) {
                continue;
            }
            for (int j = 0; j < V; j++) {
                if (dist[k][j].first == INF) {
                    continue;
                }
                PII tmp = {dist[i][k].first + dist[k][j].first, dist[i][k].second + dist[k][j].second};
                dist[i][j] = min(dist[i][j], tmp);
            }
        }
    }

    // dp(k, s) the best {step, changing cnt} to reach number k with piece 's'
    vector<vector<PII>> dp(n * n + 1, vector<PII> (3, {INF, INF}));
    for (int s = 0; s < 3; s++) {
        dp[1][s] = {0, 0};
    }
    for (int k = 1; k < n * n; k++) {
        for (int s = 0; s < 3; s++) {
            if (dp[k][s].first == INF) {
                continue;
            }
            int u = s * n * n + pos[k];
            for (int t = 0; t < 3; t++) {
                int v = t * n * n + pos[k + 1];
                if (dist[u][v].first == INF) {
                    continue;
                }
                PII tmp = {dp[k][s].first + dist[u][v].first, dp[k][s].second + dist[u][v].second};
                dp[k + 1][t] = min(dp[k + 1][t], tmp);
            }
        }
    }

    PII res = min({dp[n * n][0], dp[n * n][1], dp[n * n][2]});
    cout << res.first << ' ' << res.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}