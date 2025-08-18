#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    f[0] = 1, f[1] = 2;
    for (int i = 2; i < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (min(a, min(b, c)) < f.back() || max(a, max(b, c)) < f.back() + f[n - 2]) {
            cout << 0;
        } else {
            cout << 1;
        }
    }
    cout << '\n';
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