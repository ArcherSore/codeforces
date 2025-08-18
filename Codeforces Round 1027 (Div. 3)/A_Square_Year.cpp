#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int x = 1000 * (s[0] - '0') + 100 * (s[1] - '0') + 10 * (s[2] - '0') + (s[3] - '0');
    int t = sqrt(x);
    if (t * t == x) {
        cout << 0 << ' ' << t << '\n';
    } else {
        cout << -1 << '\n';
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