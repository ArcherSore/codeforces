#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n && x != 0 && k; i++, k--) {
        if (s[i] == 'L') {
            x -= 1;
        } else {
            x += 1;
        }
    }
    if (x != 0) {
        cout << 0 << '\n';
        return;
    }
    int cir = -1, sum = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') {
            sum -= 1;
        } else {
            sum += 1;
        }
        if (sum == 0) {
            cir = i + 1;
            break;
        }
    }
    if (cir == -1) {
        cout << 1 << '\n';
        return;
    }
    LL res = 1 + k / cir;
    cout << res << '\n';
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