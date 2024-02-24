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

typedef long long LL;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int f[MAXN][2]; // 0->P 1->S

void dfs(vector<vector<int>> &G, vector<char> &chr, int lvl) {
    f[lvl][0] = f[lvl][1] = 0;
    if (chr[lvl] == 'S') {
        f[lvl][0] = INF;
    }
    if (chr[lvl] == 'P') {
        f[lvl][1] = INF;
    }
    for (auto child : G[lvl]) {
        dfs(G, chr, child);
        f[lvl][0] += min(f[child][0], f[child][1] + 1);
        f[lvl][1] += min(f[child][1], f[child][0] + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        G[x].push_back(i);
    }
    vector<char> chr(n + 1);
    for (int i = 1; i <= n; i++) {
        char t;
        cin >> t;
        chr[i] = t;
    }
    dfs(G, chr, 1);
    cout << min(f[1][0], f[1][1]) << '\n';
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