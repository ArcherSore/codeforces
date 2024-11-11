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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> r(n + 1), pos;
    pos.push_back(-1);
    vector<int> intelligence(m + 1), strength(m + 1);
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
        if (r[i] > 0) {
            intelligence[r[i]] += 1;
        } else if (r[i] < 0) {
            strength[-r[i]] += 1;
        } else {
            pos.push_back(i);
        }
    }

    vector<vector<int>> f(m + 1, vector<int> (m + 1));
    int last = 0;
    for (int i = 1; i <= m; i++) {
        // delete r before pos[i] 
        int p = pos[i];
        for (int k = last + 1; k < p; k++) {
            if (r[k] > 0) {
                intelligence[r[k]]--;
            }
            if (r[k] < 0) {
                strength[-r[k]]--;
            }
        }
        last = p;
        // work
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                f[i][j] = max(f[i][j], f[i - 1][j] + strength[i - j]);
            } else {
                f[i][j] = max(f[i][j], max(f[i - 1][j] + strength[i - j], f[i - 1][j - 1] + intelligence[j]));
            }
        }
    }

    // for (int i = 1; i <= m; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int j = 0; j <= m; j++) {
        ans = max(ans, f[m][j]);
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