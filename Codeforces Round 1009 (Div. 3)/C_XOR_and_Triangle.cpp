#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int x;
    cin >> x;
    vector<int> bit;
    while (x) {
        bit.push_back(x & 1);
        x >>= 1;
    }

    int zero = 0, one = 0, p = -1;
    for (int i = 0; i < bit.size() - 1; i++) {
        if (bit[i] == 0) {
            zero = 1;
        } else {
            one = 1;
        }
        if (zero && one) {
            p = i;
            break;
        }
    }
    if (p == -1) {
        cout << -1 << '\n';
        return;
    }
    int res = 1;
    for (int i = p - 1; i >= 0; i--) {
        res <<= 1;
        res |= 1;
    }
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