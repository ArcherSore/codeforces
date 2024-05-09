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

int n, k;
int cnt, rest; // cnt分成几块

int dfs(int u, int fa, vector<vector<int>> &G, int mid) {
    int num = 1;
    for (auto v : G[u]) {
        if (v != fa) {
            num += dfs(v, u, G, mid);
        }
    }
    if (num >= mid) {
        cnt++;
        num = 0;
    }
    return num;
}

void solve() {
    cin >> n >> k;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int l = 1, r = n, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        cnt = 0;
        rest = dfs(1, 0, G, mid);
        if (cnt > k || (cnt == k && rest >= mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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