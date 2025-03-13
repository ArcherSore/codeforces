#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        sum += t;
    }
    if (sum % n) {
        cout << "NO\n";
        return;
    }
    if (sum / n == x) {
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