// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

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
    
    int size(int x) {
        return siz[find(x)];
    }
};

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<tuple<int, int, int>> e1, e2;
    for (int i = 0; i < m1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e1.push_back({a, b, 0});
    }
    DSU dsu(n), dsu2(n);
    for (int i = 0; i < m2; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        e2.push_back({a, b, 0});

        dsu.merge(a, b);
    }

    int res = 0;
    for (auto &[a, b, rem] : e1) {
        if (dsu.find(a) != dsu.find(b)) {
            rem = 1;
            res += 1;
        }
    }

    for (auto [a, b, rem] : e1) {
        if (rem) {
            continue;
        }
        dsu2.merge(a, b);
    }
    for (auto [a, b, rem] : e2) {
        if (dsu2.find(a) != dsu2.find(b)) {
            res += 1;
            dsu2.merge(a, b);
        }
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