#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < x; i++) {
        cout << i << ' ';
    }
    for (int i = x + 1; i < n; i++) {
        cout << i << ' ';
    }
    if (x != n) {
        cout << x;
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