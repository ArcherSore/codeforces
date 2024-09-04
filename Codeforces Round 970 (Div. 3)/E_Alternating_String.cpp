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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s;

    vector<vector<vector<int>>> cnt(n + 1, vector<vector<int>> (26, vector<int> (2)));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt[i][j][0] = cnt[i - 1][j][0];
            cnt[i][j][1] = cnt[i - 1][j][1];
        }
        cnt[i][s[i] - 'a'][i % 2]++;
    }

    if (n % 2 == 0) {
        int mx0 = 0, mx1 = 0;
        for (int i = 0; i < 26; i++) {
            mx0 = max(mx0, cnt[n][i][0]);
            mx1 = max(mx1, cnt[n][i][1]);
        }
        cout << n - mx0 - mx1 << '\n';
    } else {
        int ans = n;
        for (int i = n; i >= 1; i--) {
            int mx0 = 0, mx1 = 0;
            for (int j = 0; j < 26; j++) {
                mx0 = max(mx0, cnt[i - 1][j][0] + cnt[n][j][1] - cnt[i][j][1]);
                mx1 = max(mx1, cnt[i - 1][j][1] + cnt[n][j][0] - cnt[i][j][0]);
            }
            ans = min(ans, n - mx0- mx1);
        }
        cout << ans << '\n';
    }
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