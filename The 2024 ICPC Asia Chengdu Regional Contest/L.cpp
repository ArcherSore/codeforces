#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << 100 << '\n';
    for (int i = 1; i <= 50; i++) {
        cout << a << ' ';
    }
    for (int i = 51; i <= 95; i++) {
        cout << b << ' ';
    }
    for (int i = 96; i <= 99; i++) {
        cout << c << ' ';
    }
    cout << c + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}