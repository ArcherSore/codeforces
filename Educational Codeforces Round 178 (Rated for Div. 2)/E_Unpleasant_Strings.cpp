#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '$' + s;

    vector<vector<int>> nxt(n + 1, vector<int>(k));
    for (int j = 0; j < k; j++) {
        int p = 0;
        for (int i = 0; i <= n; i++) {
            while (p <= n && (p <= i || s[p] != j + 'a')) {
                p++;
            }
            if (p <= n) {
                nxt[i][j] = p;
            } else {
                nxt[i][j] = -1;
            }
        }
    }

    vector<int> dp(n + 1, 0);
    for (int p = n; p >= 0; p--) {
        int best = INF;
        for (int j = 0; j < k; j++) {
            if (nxt[p][j] == -1) {
                best = 1;
                break;
            } else {
                best = min(best, 1 + dp[nxt[p][j]]);
            }
        }
        dp[p] = best;
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int p = 0;
        bool flag = true;
        for (char c : t) {
            p = nxt[p][c - 'a'];
            if (p == -1) {
                flag = false;
                break;
            }
        }
        if (!flag) {
            cout << 0 << "\n";
            continue;
        }
        cout << dp[p] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}