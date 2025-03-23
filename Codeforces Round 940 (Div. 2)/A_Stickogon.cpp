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
    
    int res = 0;
    for (auto [i, c] : cnt) {
        res += c / 3;
    }
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