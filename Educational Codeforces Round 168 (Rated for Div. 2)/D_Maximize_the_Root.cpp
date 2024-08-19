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

int dfs(int u, vector<int> &a, vector<vector<int>> &G) {
    if (G[u].empty()) {
        return a[u];
    }

    int minn = 1e9;
    for (auto v : G[u]) {
        minn = min(minn, dfs(v, a, G));
    }

    if (u == 0) {
        return a[u] + minn;
    } else {
        if (a[u] < minn) {
            return (a[u] + minn) / 2;
        } else {
            return minn;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> G(n);
    for (int i = 1; i < n; i++) {
        int u;
        cin >> u;
        G[u - 1].push_back(i);
    }

    int ans = dfs(0, v, G);
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