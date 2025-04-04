#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e5 + 1;
vector<int> father(N), siz(N), son(N, -1);
vector<vector<int>> adj(N);

void dfs1(int u, int fa) {
    father[u] = fa;
    siz[u] = 1;
    for (auto v : adj[u]) {
        if (v == fa) {
            continue;
        }
        dfs1(v, u);
        siz[u] += siz[v];
    }
    for (auto v : adj[u]) {
        if (v == fa) {
            continue;
        }
        if (son[u] == -1 || siz[son[u]] < siz[v]) {
            son[u] = v;
        }
    }
}

vector<int> c(N);
vector<int> colorCnt(N), maxCnt(N);
vector<LL> res(N);

void effect(int u, int fa) {
    colorCnt[c[u]]++;
    if (colorCnt[c[u]] == maxCnt[fa]) {
        res[fa] += c[u];
    } else if (colorCnt[c[u]] > maxCnt[fa]) {
        maxCnt[fa] = colorCnt[c[u]];
        res[fa] = c[u];
    }
    for (auto v : adj[u]) {
        if (v == father[u]) {
            continue;
        }
        effect(v, fa);
    }
}

void cancel(int u) {
    colorCnt[c[u]]--;
    for (auto v : adj[u]) {
        if (v == father[u]) {
            continue;
        }
        cancel(v);
    }
}

void dfs2(int u, int keep) {
    for (auto v : adj[u]) {
        if (v == father[u] || v == son[u]) {
            continue;
        }
        dfs2(v, 0);
    }
    if (son[u] != -1) {
        dfs2(son[u], 1);
        maxCnt[u] = maxCnt[son[u]];
        res[u] = res[son[u]];
    }
    colorCnt[c[u]]++;
    if (colorCnt[c[u]] == maxCnt[u]) {
        res[u] += c[u];
    } else if (colorCnt[c[u]] > maxCnt[u]) {
        maxCnt[u] = colorCnt[c[u]];
        res[u] = c[u];
    }
    for (auto v : adj[u]) {
        if (v == father[u] || v == son[u]) {
            continue;
        }
        effect(v, u);
    }
    if (keep == 0) {
        cancel(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, 0);

    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }

    return 0;
}