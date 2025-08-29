#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

struct Node {
    int u, from, d;
};

/*  
    #1 如果不存在任何度 > 3 的节点，答案就是 -1
    #2 如果存在某个度 > 3 的节点 b，并且与它相连的节点存在一个度 = 1 的节点 c，选这个就应该不会错 吧？
    #3 如果都不是，怎么办？？？

    那么如果都不是，应该是个什么样的形状？每个节点伸出去的都是直的链条？（也就是叶子到分叉点中间存在度 = 2 的节点）

    所以可以认为是找每个度 > 3 的节点（作为根节点），到叶子最近的距离的最小值 {的最小值}？

    我好像知道哪错了 我确定了 b 和 c，但是 a 现在是随便选了一个，会不会这里出问题？
    如果我不动的 a 选那个最深的？也就是需要移动次数最多的不动？

    又wa了！！！
    摸了几下感觉到叶子节点距离最小貌似有点小问题，又感觉最初想的树的直径没毛病了？
    每次操作能让直径增加 1，因为始终可以选择一个在直径的点 b，和不在直径的点 c
    感觉没啥毛病啊 前面呆了 摸直径的时候摸错了......
*/
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    vector<int> dist(n), parent(n);
    auto dfs = [&](auto &&self, int u, int fa) -> void {
        parent[u] = fa;
        for (int v : adj[u]) {
            if (v == fa) {
                continue;
            }
            dist[v] = dist[u] + 1;
            self(self, v, u);
        }
    };
    dfs(dfs, 0, -1);

    int st = -1, ed = -1;
    int best = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        if (dist[i] == best) {
            st = i;
            break;
        }
    }

    dist[st] = 0;
    dfs(dfs, st, -1);
    best = *max_element(dist.begin(), dist.end());
    for (int i = 0; i < n; i++) {
        if (dist[i] == best) {
            ed = i;
            break;
        }
    }

    if (dist[ed] == n - 1) {
        cout << -1 << '\n';
        return;
    }
    for (int u = ed, pre = -1; u != st; pre = u, u = parent[u]) {
        for (int v : adj[u]) {
            if (v == pre || v == parent[u]) {
                continue;
            }
            cout << (u == st ? pre + 1 : parent[u] + 1) << ' ' << u + 1 << ' ' << v + 1 << '\n';
            return;
        }
    }
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