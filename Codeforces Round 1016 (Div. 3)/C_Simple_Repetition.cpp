#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int x, k;
    cin >> x >> k;
    if (is_prime(x) && k == 1 || x == 1 && k == 2) {
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