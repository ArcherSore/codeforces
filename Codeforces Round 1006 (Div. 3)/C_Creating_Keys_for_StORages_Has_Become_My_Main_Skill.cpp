#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;

    int t = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            if ((t | i) == x) {
                cout << i << ' ';
            } else {
                cout << x << ' ';
            }
            break;
        }
        if (((t | i) & x) == (t | i)) {
            t |= i;
            cout << i << ' ';
        } else {
            cout << 0 << ' ';
        }
        
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