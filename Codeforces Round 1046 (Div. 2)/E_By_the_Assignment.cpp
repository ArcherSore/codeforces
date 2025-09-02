#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 998244353;

set<pair<int, int>> E;

struct EBCC {
    int n;
    vector<vector<int>> adj;
    vector<int> stk;
    vector<int> dfn, low, bel;
    int cur, cnt;
    
    EBCC() {}
    EBCC(int n) {
        init(n);
    }
    
    void init(int n) {
        this->n = n;
        adj.assign(n, {});
        dfn.assign(n, -1);
        low.resize(n);
        bel.assign(n, -1);
        stk.clear();
        cur = cnt = 0;
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    void dfs(int x, int p) {
        dfn[x] = low[x] = cur++;
        stk.push_back(x);
        
        for (auto y : adj[x]) {
            if (y == p) {
                continue;
            }
            if (dfn[y] == -1) {
                E.emplace(x, y);
                dfs(y, x);
                low[x] = min(low[x], low[y]);
            } else if (bel[y] == -1 && dfn[y] < dfn[x]) {
                E.emplace(x, y);
                low[x] = min(low[x], dfn[y]);
            }
        }
        
        if (dfn[x] == low[x]) {
            int y;
            do {
                y = stk.back();
                bel[y] = cnt;
                stk.pop_back();
            } while (y != x);
            cnt++;
        }
    }
    // 返回所属边双连通分量编号
    vector<int> work() {
        dfs(0, -1);
        return bel;
    }
    
    // 缩点后的图
    struct Graph {
        int n;
        vector<pair<int, int>> edges;
        vector<int> siz; // 每个连通分量包含的点数
        vector<int> cnte; // 每个连通分量内部的边数
    };
    Graph compress() {
        Graph g;
        g.n = cnt;
        g.siz.resize(cnt);
        g.cnte.resize(cnt);
        for (int i = 0; i < n; i++) {
            g.siz[bel[i]]++;
            for (auto j : adj[i]) {
                if (bel[i] < bel[j]) {
                    g.edges.emplace_back(bel[i], bel[j]);
                } else if (i < j) {
                    g.cnte[bel[i]]++;
                }
            }
        }
        return g;
    }
};


void solve() {
    int n, m, V;
    cin >> n >> m >> V;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    EBCC g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.addEdge(u, v);
    }

    vector<int> bel = g.work();
    vector<vector<int>> cnt(g.cnt);
    for (int i = 0; i < n; i++) {
        cnt[bel[i]].push_back(i);
    }
    // for (auto v : cnt) {
    //     for (auto x : v) {
    //         cerr << x << ' ';
    //     }
    //     cerr << '\n';
    // }
    // cerr << "---\n";
    vector<int> vis(n, -1);
    auto check = [&](vector<int>& nodes) {
        queue<int> q;
        for (int s : nodes) {
            if (vis[s] == -1) {
                vis[s] = 0;
                q.push(s);
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    for (int v : g.adj[u]) {
                        if (bel[v] != bel[u]) {
                            continue;
                        }
                        if (vis[v] == -1) {
                            vis[v] = vis[u] ^ 1;
                            q.push(v);
                        } else if (vis[v] == vis[u]) {
                            return false; // 有奇环
                        }
                    }
                }
            }
        }
        return true; // 没有奇环
    };
    ll res = 1;
    for (auto v : cnt) {
        if (v.size() == 1) {
            if (a[v[0]] == -1) {
                res = res * V % mod;
            }
        } else if (!check(v)) {
            int same = 1;
            for (auto u : v) {
                if (a[u] == -1) {
                    continue;
                }
                if (a[u] != 0) {
                    same = 0;
                }
            }
            if (!same) {
                cout << 0 << '\n';
                return;
            }
        } else {
            set<int> num;
            for (auto u : v) {
                if (a[u] != -1) {
                    num.insert(a[u]);
                }
            }
            if (num.size() > 1) {
                cout << 0 << '\n';
                return;
            }
            if (num.size() == 0) {
                res = res * V % mod;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // ll x = 1e9;
    // cerr << (x * x % mod) * x % mod << '\n';

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}