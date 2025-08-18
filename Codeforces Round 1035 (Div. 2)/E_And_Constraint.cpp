#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n - 1), b(n);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }

    vector<ll> M(n); // b[i]的最终值必须含有M[i]中的1
    for (int i = 0; i < n; i++) {
        M[i] = (i ? a[i - 1] : 0) | (i < n - 1 ? a[i] : 0);
    }
    vector<vector<ll>> C(n); // b[i]的最终值候选值集合C[i]
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 34; k++) {
            // 高于k位的不变，低于k位的为0，第k位为1
            // 再 or M[i]
            if (((b[i] >> k) & 1) == 0) {
                C[i].push_back((((b[i] >> k) | 1) << k) | M[i]);
            }
        }
        C[i].push_back(b[i] | M[i]); // b[i]本身
        sort(C[i].begin(), C[i].end());
        C[i].erase(unique(C[i].begin(), C[i].end()), C[i].end());
    }
    // dp(i, j) 用C[i][j]作为b[i]的最终值且满足约束的最小代价
    vector<vector<ll>> dp(n, vector<ll> (34, inf));
    for (int j = 0; j < C[0].size(); j++) {
        dp[0][j] = C[0][j] - b[0];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < C[i].size(); j++) {
            for (int k = 0; k < C[i + 1].size(); k++) {
                if ((C[i][j] & C[i + 1][k]) == a[i]) {
                    dp[i + 1][k] = min(dp[i + 1][k], dp[i][j] + C[i + 1][k] - b[i + 1]);
                }
            }
        }
    }
    ll res = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    cout << (res == inf ? -1 : res) << '\n';
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