#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, s;
    cin >> n >> s;
    int cnt = 0;
    while (n--) {
        int dx, dy, x, y;
        cin >> dx >> dy >> x >> y;
        if (dx * dy > 0 && x == y) {
            cnt++;
        }
        if (dx * dy < 0 && x + y == s) {
            cnt++;
        }
    }
    cout << cnt << '\n';
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