#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += (i * i - (i - 1) * (i - 1)) * i;
    }
    int opt = 2 * n - 1;
    cout << sum << ' ' << opt << '\n';

    vector<int> p(n);
    iota(p.begin(), p.end(), 1);

    auto output = [&](int c, int k) ->void {
        cout << c << ' ' << k << ' ';
        for (auto x : p) {
            cout << x << ' ';
        }
        cout << '\n';
    };

    int row = n, col = n - 1;
    output(1, row);
    row--;
    for (int i = 1; i < n; i++) {
        output(1, row);
        output(2, col);
        col--, row--;
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