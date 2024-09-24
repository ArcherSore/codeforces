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

vector<char> stdd = {'n', 'a', 'r', 'e', 'k'};

int score(string &s, int p) {
    int scr = 0;
    for (auto c : s) {
        if (c == 'n' || c == 'a' || c == 'r' || c == 'e' || c == 'k') {
            scr -= 1;
        }
        if (c == stdd[p % 5]) {
            if (c == 'k') {
                scr += 10;
            }
            p++;
        }
    }
    return scr;
}

int nxt(string &s, int p) {
    for (auto c : s) {
        if (c == stdd[p % 5]) {
            p++;
        }
    }
    return p % 5;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> f(n + 1, vector<int> (5, -1e9));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int k = 0; k < 5; k++) {
            f[i][k] = max(f[i][k], f[i - 1][k]);

            int next = nxt(s, k), scr = score(s, k);
            f[i][next] = max(f[i][next], f[i - 1][k] + scr);
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    int ans = 0;
    for (int i = 0; i < 5; i++) {
        ans = max(ans, f[n][i]);
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