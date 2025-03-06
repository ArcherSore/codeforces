#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (auto &x : p) {
        cin >> x;
        x--;
    }
    vector<int> vis(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        int x = i, len = 0;
        while (!vis[p[x]]) {
            x = p[x];
            vis[x] = 1;
            len++;
        }
        res += (len - 1) / 2;
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