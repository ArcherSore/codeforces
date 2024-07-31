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

const int MOD = 1e9 + 7;
const int MAXN = 5010;

vector<vector<LL>> C(MAXN, vector<LL> (MAXN));

void init() {
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
            }
        }
    }
}

void solve() {
    LL n;
    cin >> n;

    LL res = 0;
    for (LL k = 0; k <= n; k++) {
        int tot = 0;
        if (2 * k >= n) {
            res += (C[n][k] * (2 * k + 1)) % MOD;
            res %= MOD;
        } else {
            for (LL m = k + 1; m <= 2 * k + 1; m++) {
                res += ((C[m - 1][m - k - 1] * C[n - m][2 * k - m + 1] % MOD) * m) % MOD;
                res %= MOD;
            }
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}