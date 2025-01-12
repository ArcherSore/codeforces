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

const int INF = 2e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> pos(q), dir(q);
    for (int i = 0; i < q; i++) {
        char _dir;
        cin >> pos[i] >> _dir;
        pos[i]--;
        dir[i] = (_dir == '+' ? 1 : 0);
    }

    vector<vector<int>> dist(n, vector<int> (n, 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int diff = 0;
            for (int k = 0; k < q; k++) {
                if (pos[k] == i && dir[k] == 1) {
                    // the pre snake enlarges
                    if (diff) {
                        // enough space
                        diff--;
                    } else {
                        // not enough space, initial dist + 1
                        dist[i][j]++;
                    }
                }
                if (pos[k] == j && dir[k] == 0) {
                    // the new snake shrinks, one new space available
                    diff++;
                }
            }
        }
    }

    vector<vector<int>> f((1 << n), vector<int> (n, INF));
    for (int i = 0; i < n; i++) {
        f[0][i] = 0;
    }
    for (int s = 0; s < (1 << n); s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((!s && s & (1 << i) == 0) || s & (1 << j)) {
                    // the last snake doesn't exist(except for state == 0) or the one to add already exists
                    continue;
                }
                f[s | (1 << j)][j] = min(f[s | (1 << j)][j], f[s][i] + dist[i][j]);
            }
        }
    }
    // for (int i = 0; i < (1 << n); i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < q; k++) {
            if (pos[k] == i && dir[k] == 1) {
                f[(1 << n) - 1][i]++;
            }
        }
        ans = min(ans, f[(1 << n) - 1][i]);
    }
    cout << ans << '\n';
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
