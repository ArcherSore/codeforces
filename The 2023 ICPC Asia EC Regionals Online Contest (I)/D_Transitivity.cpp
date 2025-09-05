#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct DSU {
    vector<int> f, siz;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        f.resize(n);
        iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    vector<pii> edges(m);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[i] = {u, v};
        dsu.merge(u, v);
    }
    
    vector<ll> cnt(n, 0);
    for (auto &e : edges) {
        int u = e.first;
        int rep = dsu.find(u);
        cnt[rep]++;
    }
    
    vector<int> siz;
    ll res = 0;
    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            int s = dsu.siz[i];
            siz.push_back(s);
            ll need = 1LL * s * (s - 1) / 2 - cnt[i];
            res += need;
        }
    }
    
    if (res > 0) {
        cout << res << "\n";
    } else {
        sort(siz.begin(), siz.end());
        res = 1LL * siz[0] * siz[1];
        cout << res << "\n";
    }
    
    return 0;
}