#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    for (auto [x, c] : cnt) {
        if (c >= k) {
            cout << k - 1 << '\n';
            return;
        }
    }
    cout << n << '\n';
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