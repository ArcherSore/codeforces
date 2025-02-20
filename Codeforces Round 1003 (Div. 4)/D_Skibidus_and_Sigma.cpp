#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<tuple<LL, int, int>> rate(n);
    for (int i = 0; i < n; i++) {
        LL sum = accumulate(a[i].begin(), a[i].end(), 0);
        rate[i] = {sum, a[i][0], i};
    }
    sort(rate.begin(), rate.end(), greater<>());

    LL k = n * m, res = 0;
    for (auto [_, __, i] : rate) {
        for (auto x : a[i]) {
            res += k * x;
            k--;
        }
    }
    cout << res << '\n';
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