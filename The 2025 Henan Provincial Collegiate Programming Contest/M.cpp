#include <bits/stdc++.h>
using namespace std;

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
    int size(int x) {
        return siz[find(x)];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    vector<pair<int, int>> e(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        dsu.merge(u, v);
        e[i] = {u, v};
    }
    
    int bcnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == dsu.find(i)) {
            bcnt++;
        }
    }

    vector<int> cnt(n, 0);
    for (auto [u, v] : e) {
        int rt = dsu.find(u);
        cnt[rt]++;
    }
    int res = bcnt - 1;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        res += cnt[i] - dsu.size(i) + 1;
    }
    cout << res << '\n';

    return 0;
}

// 32:49