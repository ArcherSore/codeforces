#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1) {
            cnt1 ++;
        } else {
            cnt2 ++;
        }
    }
    if (cnt2 == 0) {
        cout << max(0, cnt1 - 1) << '\n';
    } else {
        cout << cnt1 + 1 << '\n';
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