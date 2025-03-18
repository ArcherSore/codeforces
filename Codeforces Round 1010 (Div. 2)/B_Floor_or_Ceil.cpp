#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int workmin(int x, int n, int m) {
    while (m--) {
        x = (x + 1) / 2;
    }
    while (n--) {
        x /= 2;
    }
    return x;
}

int workmax(int x, int n, int m) {
    while (n--) {
        x /= 2;
    }
    while (m--) {
        x = (x + 1) / 2;
    }
    return x;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    n = min(n, 31);
    m = min(m, 31);
    cout << workmin(x, n, m) << ' ' << workmax(x, n, m) << '\n';
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