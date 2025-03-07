#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n == 1 || n == 3) {
        cout << -1 << '\n';
        return;
    }
    if (n == 2) {
        cout << 66 << '\n';
        return;
    }
    string res;
    res.append(n / 2 * 2 - 3, '3');
    if (n & 1) {
        res.push_back('6');
    }
    res.push_back('3');
    res.append(2, '6');
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