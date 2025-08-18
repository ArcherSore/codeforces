#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '0') {
            c0++;
        } else {
            c1++;
        }
    }
    if (n / 2 < k || n / 2 - k > c0 || n / 2 - k > c1) {
        cout << "NO\n";
        return;
    }

    if ((c0 - n / 2 + k) % 2 == 0 && (c1 - n / 2 + k) % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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