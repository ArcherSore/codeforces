#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << '\n';
        return;
    }
    int x = n;
    while (x > 0) {
        cout << x << ' ';
        x -= 2;
    }
    x = 2;
    while (x <= n) {
        cout << x << ' ';
        x += 2;
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