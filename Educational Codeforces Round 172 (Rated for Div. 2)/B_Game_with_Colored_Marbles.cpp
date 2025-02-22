#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int sing = 0, doub = 0;
    for (auto [x, c] : cnt) {
        if (c == 1) {
            sing++;
        } else {
            doub++;
        }
    }
    sing = (sing + 1) / 2;
    int res = 2 * sing + doub;
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