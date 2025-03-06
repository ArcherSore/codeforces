#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int x = 0;
    for (int i = 1; ; i++) {
        if (i & 1) {
            x -= (2 * i - 1);
        } else {
            x += (2 * i - 1);
        }
        if (abs(x) > n) {
            if (i & 1) {
                cout << "Sakurako\n";
            } else {
                cout << "Kosuke\n";
            }
            break;
        }
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