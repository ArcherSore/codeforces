#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int l1, b1, l2, b2, l3, b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
    if (l1 == l2 && l2 == l3 && b1 + b2 + b3 == l1) {
        cout << "YES\n";
        return;
    }
    if (b1 == b2 && b2 == b3 && l1 + l2 + l3 == b1) {
        cout << "YES\n";
        return;
    }
    if (l2 == l3 && b2 + b3 == b1 && b1 == l1 + l2) {
        cout << "YES\n";
        return;
    }
    if (b2 == b3 && l2 + l3 == l1 && l1 == b1 + b2) {
        cout << "YES\n";
        return;
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