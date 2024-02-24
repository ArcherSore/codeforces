#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath> 
#include <cstring>
#include <queue>
#include <numeric>
#include <set> 
#include <stack> 
#include <map>
using namespace std;

using LL = long long;

const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;

void dfs(vector<vector<int>> &G, vector<char> &opt, vector<int> &dp, int u) {
    int lchi = G[u][0], rchi = G[u][1];
    if (!lchi && !rchi) {
        dp[u] = 0;
        return;
    }
    if (lchi) {
        dfs(G, opt, dp, lchi);
    }
    if (rchi) {
        dfs(G, opt, dp, rchi);
    }
    dp[u] = min(dp[lchi] + (opt[u] == 'L' ? 0 : 1), dp[rchi] + (opt[u] == 'R' ? 0 : 1));
}

void solve() {
    int n;
    cin >> n;
    vector<char> opt(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> opt[i];
    }
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= n; i++) {
        int lchi, rchi;
        cin >> lchi >> rchi;
        G[i].push_back(lchi);
        G[i].push_back(rchi);
    }
    vector<int> dp(n + 1, INF);
    dfs(G, opt, dp, 1);
    cout << dp[1] << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}