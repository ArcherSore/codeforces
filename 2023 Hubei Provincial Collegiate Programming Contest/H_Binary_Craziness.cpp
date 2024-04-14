#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const LL MOD = 998244353;

LL cal(LL i, LL j) {
    return (i ^ j) * (i | j) * (i & j) % MOD;
}

void solve() {
    LL n, m;
    cin >> n >> m;

    vector<LL> indeg(n + 1);
    for (int i = 0; i < m; i++) {
        LL a, b;
        cin >> a >> b;
        indeg[a]++, indeg[b]++;
    }

    // cout << "indeg:\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << indeg[i] << " "; 
    // }
    // cout << '\n';

    map<LL, LL> mp;
    for (LL i = 1; i <= n; i++) {
        mp[indeg[i]]++;
    }
    LL n_type = mp.size();
    vector<LL> type(n_type + 1);
    LL it = 1;
    for (auto [t, num] : mp) {
        type[it] = t;
        it++;
    }
    vector<vector<LL>> f(n_type + 1, vector<LL> (n_type + 1));
    for (LL i = 1; i <= n_type; i++) {
        for (LL j = 1; j <= n_type; j++) {
            f[i][j] = cal(type[i], type[j]);
        }
    }

    // cout << "f:\n";
    // for (int i = 1; i <= n_type; i++) {
    //     for (int j = 1; j <= n_type; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';

    LL res = 0;
    for (LL i = 1; i <= n_type; i++) {
        LL tot = 0;
        for (LL j = 1; j <= n_type; j++) {
            tot += f[i][j] * mp[type[j]];
        }
        // cout << "i = " << i << " " << tot * mp[type[i]] << '\n';
        res += tot * mp[type[i]];
    }

    cout << (res / 2) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.in", "r", stdin);
    // freopen("main.out", "w", stdout);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}