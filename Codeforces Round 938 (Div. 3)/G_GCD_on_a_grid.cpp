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

int n, m;
int a[110][110];
int f[110][110];

bool check(int div) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i == 1 && j == 1) {
                f[i][j] = 1;
                continue;
            }

            if (a[i][j] % div == 0) {
                f[i][j] = f[i - 1][j] | f[i][j - 1];
            } else {
                f[i][j] = 0;
            }
        }
    }

    return f[n][m];
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    int t = gcd(a[1][1], a[n][m]);
    for (int i = 1; i * i <= t; i++) {
        if (t % i == 0) {
            if (check(t / i)) {
                ans = max(ans, t / i);
            }
            if (check(i)) {
                ans = max(ans, i);
            }
        }
    }
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