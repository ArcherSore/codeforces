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

int cnt;

void dfs(int u, vector<int> &vis, vector<int> &a) {
    if (vis[u]) {
        return;
    }
    vis[u] = 1;
    cnt += 1;
    dfs(a[u], vis, a);
    return;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = 100;
    vector<int> vis(n + 1);
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            cnt = 0;
            dfs(i, vis, a);
            // cout << cnt << " ";
            res = min(res, cnt);
        }
    }
    if (res == 2) {
        cout << 2 << '\n';
    } else {
        cout << 3 << '\n';
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