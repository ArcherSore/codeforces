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

void solve() {
    int n;
    cin >> n;
    vector<set<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].insert(v);
        G[v].insert(u);
    }

    vector<int> fa(n);
    auto dfs = [&](auto &self, int u, int father) -> void {
        fa[u] = father;
        for (auto v : G[u]) {
            if (v == father) {
                continue;
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);

    int ans = n - 1, count = n - 1;
    queue<int> q, del;
    vector<int> nodes;
    q.push(0);
    while (!q.empty()) {
        nodes.clear();
        while (!q.empty()) {
            for (auto u : G[q.front()]) {
                if (u == fa[q.front()]) {
                    continue;
                }
                nodes.push_back(u);
            }
            q.pop();
        }
        int cost = 0;
        while (!del.empty()) {
            int u = del.front();
            del.pop();
            int v = *G[u].begin();
            G[u].erase(G[u].begin());
            G[v].erase(G[v].find(u));
            cost += 1;
            while (G[v].size() == 1 && v != 0) {
                u = v;
                v = *G[u].begin();
                G[u].erase(G[u].begin());
                G[v].erase(G[v].find(u));
                cost += 1;
            }
        }
        count = count - nodes.size() + cost;
        ans = min(ans, count);

        for (auto u : nodes) {
            if (G[u].size() == 1) {
                del.push(u);
            }
            q.push(u);
        }
    }

    cout << ans << '\n';
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