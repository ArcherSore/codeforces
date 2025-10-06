#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

struct Dinic {
    struct Edge {
        int to;
        ll cap;
        Edge(int to, ll cap) : to(to), cap(cap) {}
    };
    int n;
    vector<Edge> e;
    vector<vector<int>> adj;
    vector<int> cur, d;

    Dinic() {}
    Dinic(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        e.clear();
        adj.assign(n, {});
        cur.resize(n);
        d.resize(n);
    }

    void addEdge(int u, int v, ll c) {
        adj[u].push_back(e.size());
        e.emplace_back(v, c);
        adj[v].push_back(e.size());
        e.emplace_back(u, 0);
    }

    bool bfs(int s, int t) {
        d.assign(n, -1);
        queue<int> q;
        d[s] = 0;
        q.push(s);
        while (!q.empty()) {
            // cerr << "ok_bfs\n";
            int u = q.front();
            q.pop();
            for (int i : adj[u]) {
                // cerr << "check_" << i << '\n';
                auto [v, c] = e[i];
                if (c > 0 && d[v] == -1) {
                    d[v] = d[u] + 1;
                    if (v == t) {
                        return true;
                    }
                    q.push(v);
                }
            }
        }
        return false;
    }

    ll dfs(int u, int t, ll f) {
        if (u == t) {
            return f;
        }
        auto r = f;
        for (int &i = cur[u]; i < adj[u].size(); i++) {
            int j = adj[u][i];
            auto [v, c] = e[j];
            if (c > 0 && d[v] == d[u] + 1) {
                auto a = dfs(v, t, min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0) {
                    return f;
                }
            }
        }
        return f - r;
    }

    ll work(int s, int t) {
        ll res = 0;
        // cerr << "s = " << s << ' ' << "t = " << t << '\n';
        while (bfs(s, t)) {
            // cerr << "ok_work\n";
            cur.assign(n, 0);
            res += dfs(s, t, inf);
        }
        return res;
    }
};

struct Dish {
    int x, y;
    ll w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<ll> a(n), V(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> V[i];
    }
    ll eat = 0, totDish = 0;
    vector<Dish> dishes(m);
    for (auto &[x, y, w] : dishes) {
        cin >> x >> y >> w;
        x--, y--;
        totDish += w;
        if (x == 0 || y == 0) {
            eat += w;
        }
    }

    ll mx = min(a[0], eat + V[0]);
    vector<ll> mxcst(n);
    // cerr << mx << '\n';
    mxcst[0] = mx - V[0];
    for (int i = 1; i < n; i++) {
        if (V[i] >= mx) {
            cout << "NO\n";
            return 0;
        }
        mxcst[i] = max(0LL, min(mx - 1, a[i]) - V[i]);
        // cerr << mxcst[i] << ' ';
        // if (mxcst[i] < 0) {
        //     cout << "NO\n";
        //     return 0;
        // }
    }

    // [0, m) + [m, m + n)
    int s = m + n, t = m + n + 1;
    Dinic flow(m + n + 2);
    for (int i = 0; i < m; i++) {
        auto &d = dishes[i];
        flow.addEdge(s, i, d.w);
        flow.addEdge(i, d.x + m, d.w);
        flow.addEdge(i, d.y + m, d.w);
    }
    for (int i = 0; i < n; i++) {
        flow.addEdge(i + m, t, mxcst[i]);
    }
    ll res = flow.work(s, t);
    if (res == totDish) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}