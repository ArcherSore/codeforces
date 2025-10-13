#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> vis(102);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }
    for (int i = 0; i <= 101; i++) {
        if (!vis[i]) {
            cout << i << '\n';
            return;
        }
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