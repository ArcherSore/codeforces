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

LL fast_pow(LL a, LL b) {
    a %= MOD;
    LL res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
void solve() {
    LL n, m;
    cin >> n >> m;
    LL tmp = fast_pow((m - 1), n * (MOD - 2));
    for(int k = 1; k <= m; k++) { 
        LL tmpp = fast_pow(m - k, n);
        LL ans = tmp * tmpp % MOD;
        cout << ans << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}