#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    // int n;
    // cin >> n;
    // vector<int> v(n * n);
    // iota(v.begin(), v.end(), 1);
    // do {
    //     set<int> t;
    //     for (int i = 0; i < n * n; i++) {
    //         if ((i % n) + 1 < n) {
    //             t.insert(v[i] + v[i + 1]);
    //         }
    //         if (i + n < n * n) {
    //             t.insert(v[i] + v[i + n]);
    //         }
    //     }
    //     if (t.size() == 2 * n * (n - 1)) {
    //         for (int i = 0; i < n; i++) {
    //             for (int j = 0; j < n; j++) {
    //                 cout << v[i * n + j] << ' ';
    //             }
    //             cout << '\n';
    //         }
    //     }
    // } while (next_permutation(v.begin(), v.end()));
    // cout << '\n';

    int n, m;
    cin >> n >> m;
    vector<vector<int>> res(n, vector<int> (m));
    if (n % 2 && m % 2) {
        for (int i = 0, x = 1; i < n; i++) {
            for (int j = i; j < i + m; j++, x++) {
                res[i][j % m] = x;
            }
        }
    } else {
        if (n % 2 == 0) {
            for (int j = 0, x = 1; j < m; j++) {
                for (int i = 0; i < n; i++, x++) {
                    res[i][j] = x;
                }
            }
        } else {
            for (int i = 0, x = 1; i < n; i++) {
                for (int j = 0; j < m; j++, x++) {
                    res[i][j] = x;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("out.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}