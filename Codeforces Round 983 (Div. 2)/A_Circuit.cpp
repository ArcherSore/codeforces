#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0, x; i < 2 * n; i++) {
        cin >> x;
        if (x == 0) {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    cout << (cnt0 % 2 ? 1 : 0) << ' ' << min(cnt0, cnt1) << '\n';
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