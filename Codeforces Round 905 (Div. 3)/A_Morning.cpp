#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int ans = 0, cur = 1;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        if (x == 0) x = 10;
        ans += abs(x - cur) + 1;
        cur = x;
    }
    cout << ans << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}