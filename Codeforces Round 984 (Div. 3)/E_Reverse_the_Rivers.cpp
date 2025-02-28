#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

LL INF = 1e18;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<vector<int>> a(k, vector<int> (n));
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < k; i++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < n; j++) {
            a[i][j] |= a[i][j - 1];
        }
    }

    while (q--) {
        int m;
        cin >> m;

        int st = 0, end = n; // [st, end)
        while (m--) {
            int p, c;
            char o;
            cin >> p >> o >> c;
            p--;
            
            if (o == '>') {
                // 第一个大于c的数
                auto it = upper_bound(a[p].begin(), a[p].end(), c) - a[p].begin();
                if (it > st) {
                    st = it;
                }
            } else {
                // 第一个小于c的数
                auto it = lower_bound(a[p].begin(), a[p].end(), c) - a[p].begin();
                if (it < end) {
                    end = it;
                }
            }
        }

        if (st < end) {
            cout << st + 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
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