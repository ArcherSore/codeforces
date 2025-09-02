#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    int root;
    vector<int> le(n, -1), ri(n, -1);
    auto build = [&]() -> void {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            int pre = -1;
            while (!st.empty() && a[i] > a[st.top()]) {
                pre = st.top();
                st.pop();
            }
            if (!st.empty()) {
                ri[st.top()] = i;
            }
            if (pre != -1) {
                le[i] = pre;
            }
            st.push(i);
        }
        while (st.size() > 1) {
            st.pop();
        }
        root = st.top();
    };
    build();

    vector<vector<ll>> f(n, vector<ll> (m + 1)); // 点 u 填 k, 其子树的可能数
    vector<vector<ll>> g(n, vector<ll> (m + 1)); // 点 u 填 <= k, 其子树的可能数
    auto dfs = [&](auto &&self, int u) -> void {
        if (le[u] != -1) {
            self(self, le[u]);
        }
        if (ri[u] != -1) {
            self(self, ri[u]);
        }
        for (int k = 1; k <= m; k++) {
            f[u][k] = (le[u] != -1 ? g[le[u]][k - 1] : 1LL) * (ri[u] != -1 ? g[ri[u]][k] : 1LL) % mod;
            g[u][k] = (g[u][k - 1] + f[u][k]) % mod;
        }
    };
    dfs(dfs, root);
    
    // ll res = 0;
    // for (int k = 1; k <= m; k++) {
    //     res = (res + f[root][k]) % mod;
    // }
    cout << g[root][m] << '\n';
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