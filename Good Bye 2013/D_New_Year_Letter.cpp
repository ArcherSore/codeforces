#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int k, x, n, m;
    cin >> k >> x >> n >> m;

    auto check = [&](int i, int j, char l1, char r1, char l2, char r2) -> bool {
        vector<LL> dp(k + 1);
        dp[1] = i, dp[2] = j;
        dp[3] = dp[1] + dp[2] + (r1 == 'A' && l2 == 'C');
        for (int t = 4; t <= k; t++) {
            if (t % 2) {
                dp[t] = dp[t - 1] + dp[t - 2] + (r2 == 'A' && l2 == 'C');
            } else {
                dp[t] = dp[t - 1] + dp[t - 2] + (r2 == 'A' && l1 == 'C');
            }
        }
        return dp[k] == x;
    };

    auto build = [&](string &s, int x, char l, char r, int len) -> bool {
        if (len == 1) {
            if (x != 0 || l != r) {
                return false;
            }
            s = string(1, l);
            return true;
        }

        vector<int> used;
        int lst = -2;
        for (int i = 0; i < len - 1 && used.size() < x; i++) {
            if (i == 0 && l != 'A' || i == len - 2 && r != 'C') {
                continue;
            }
            if (i <= lst + 1) {
                continue;
            }
            used.push_back(i);
            lst = i;
        }
        if (used.size() != x) {
            return false;
        }

        s.assign(len, 'B');
        s[0] = l, s[len - 1] = r;
        for (int p : used) {
            s[p] = 'A';
            s[p + 1] = 'C';
        }
        return true;
    };

    for (int i = 0; i <= n / 2; i++) {
        for (int j = 0; j <= m / 2; j++) {
            for (char l1 = 'A'; l1 <= 'C'; l1++) {
                for (int r1 = 'A'; r1 <= 'C'; r1++) {
                    for (int l2 = 'A'; l2 <= 'C'; l2++) {
                        for (int r2 = 'A'; r2 <= 'C'; r2++) {
                            if (check(i, j, l1, r1, l2, r2)) {
                                string s1, s2;
                                if (build(s1, i, l1, r1, n) && build(s2, j, l2, r2, m)) {
                                    cout << s1 << '\n' << s2;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << "Happy new year!\n";
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