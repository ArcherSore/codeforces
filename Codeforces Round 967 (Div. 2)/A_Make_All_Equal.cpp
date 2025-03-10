#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    int mx = 0;
    for (auto x : mp) {
        mx = max(mx, x.second);
    }
    cout << n - mx << '\n';
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