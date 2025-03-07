#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    // vector<int> p(n);
    // for (int i = 0; i < n; i++) {
    //     p[i] = i + 1;
    // }
    // int mx = 0;
    // set<vector<int>> res;
    // do {
    //     int k = 0;
    //     for (int i = 0; i < n; i++) {
    //         if (i & 1) {
    //             k |= p[i];
    //         } else {
    //             k &= p[i];
    //         }
    //     }
    //     if (k == mx) {
    //         res.insert(p);
    //     } else if (k > mx) {
    //         mx = k;
    //         res.clear();
    //         res.insert(p);
    //     }
    // } while (next_permutation(p.begin(), p.end()));
    
    // cout << mx << '\n';
    // for (auto v : res) {
    //     for (auto x : v) {
    //         cout << x << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    
    if (n % 2 == 0) {
        int k = __lg(n);
        cout << (1 << k + 1) - 1 << '\n';

        vector<int> vis(n + 1);
        vector<int> p;
        int i = 1;
        while ((1 << i) <= n) {
            int tmp = (1 << i);
            p.push_back(tmp - 1);
            p.push_back(tmp);
            vis[tmp - 1] = 1;
            vis[tmp] = 1;
            i++;
        }
        if (p.size() < n) {
            vis[5] = 1;
            for (int j = 1; j <= n; j++) {
                if (!vis[j]) {
                    cout << j << ' ';
                }
            }
            cout << 5 << ' ';
        }
        for (auto x : p) {
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        if (n == 3) {
            cout << 2 << '\n';
            cout << 1 << ' ' << 2 << ' ' << 3 << '\n';
        } else {
            vector<int> p = {2, 3, 1};
            int x = 4;
            while (p.size() < n) {
                p.push_back(x);
                x++;
            }

            int k = 0;
            for (int i = 0; i < n; i++) {
                if (i & 1) {
                    k |= p[i];
                } else {
                    k &= p[i];
                }
            }
            cout << k << '\n';
            for (auto t : p) {
                cout << t << ' ';
            }
            cout << '\n';
        }
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