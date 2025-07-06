#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int rx = 0, ry = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        rx = rx ^ x;
        ry = ry ^ (x + y);
    }
    cout << rx << ' ' << ry - rx << '\n';
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