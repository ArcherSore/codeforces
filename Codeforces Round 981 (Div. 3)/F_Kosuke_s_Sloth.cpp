#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

void solve() {
    LL n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << (n % MOD) << '\n';
        return;
    }
    
    LL p;
    int a = 1, b = 1;
    if (a % k == 0) {
        p = 1;
    } else if (b % k == 0) {
        p = 2;
    } else {
        for (int i = 3; i <= 6 * k; i++) {
            int c = (a + b) % k;
            if (c == 0) {
                p = i;
                break;
            }
            a = b, b = c;
        }
    }

    cout << ((n % MOD) * (p % MOD)) % MOD << '\n';
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