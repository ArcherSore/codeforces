#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    for (int i = 0; i < 7; i++) {
        s += s;
    }
    int x = 0, y = 0;
    for (auto c : s) {
        if (c == 'N') {
            y += 1;
        } else if (c == 'E') {
            x += 1;
        } else if (c == 'S') {
            y -= 1;
        } else {
            x -= 1;
        }
        if (x == a && y == b) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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