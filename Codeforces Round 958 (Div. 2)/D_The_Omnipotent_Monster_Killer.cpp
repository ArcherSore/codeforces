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

const int MAXT = 20;

void dfs(int u, int fa, int n, vector<vector<int>> &G, vector<LL> &a, vector<vector<LL>> &f) {
    for (int i = 1; i < MAXT; i++) {
       f[u][i] += i * a[u];
    }
    for (auto v : G[u]) {
        if (v == fa) {
            continue;
        }
        dfs(v, u, n, G, a, f);
        for (int i = 1; i < MAXT; i++) {
            LL mn = 1e18;
            for (int j = 1; j < MAXT; j++) {
                if (i == j) {
                    continue;
                }
                mn = min(mn, f[v][j]);
            }
            f[u][i] += mn;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<vector<LL>> f(n, vector<LL> (MAXT));
    dfs(0, -1, n, G, a, f);

    LL res = 1e18;
    for (int i = 1; i < MAXT; i++) {
        res = min(res, f[0][i]);
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