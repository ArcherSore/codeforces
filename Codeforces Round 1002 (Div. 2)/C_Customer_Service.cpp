#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int> (n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> p(n);
    for (int j = n - 1; j >= 0; j--) {
        for (int i = 0; i < n; i++) {
            if (a[i][j] == 1 && p[i] == n - j - 1) {
                p[i] += 1;
            }
        }
    }
    sort(p.begin(), p.end());
    int mex = 0;
    for (auto &x : p) {
        if (x >= mex) {
            mex++;
        }
    }
    cout << mex << '\n';
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