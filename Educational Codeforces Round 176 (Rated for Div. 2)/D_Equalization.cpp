#include <bits/stdc++.h>
using namespace std;

using LL = long long;

const int N = 60;
const LL INF = 1e18;

LL dp[N][N];

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = INF;
        }
    }

    dp[0][0] = 0;
    for (int k = 0; k < N; k++) {
        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (dp[i][j] == INF) {
                    continue;
                }
                if (i + k < N) {
                    dp[i + k][j] = min(dp[i + k][j], dp[i][j] + (1LL << k));
                }
                if (j + k < N) {
                    dp[i][j + k] = min(dp[i][j + k], dp[i][j] + (1LL << k));
                }
            }
        }
    }
}

void solve() {
    LL x, y;
    cin >> x >> y;
    
    LL res = INF;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((x >> i) == (y >> j)) {
                res = min(res, dp[i][j]);
            }
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;
    init();
    while(T--){
        solve();
    }
    
    return 0;
}