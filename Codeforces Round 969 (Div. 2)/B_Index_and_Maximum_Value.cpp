#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    
    int mx = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mx = max(mx, x);
    }

    while (m--) {
        char opt;
        int l, r;
        cin >> opt >> l >> r;
        
        if (l <= mx && mx <= r) {
            if (opt == '+') {
                mx += 1;
            } else {
                mx -= 1;
            }
        }

        cout << mx << ' ';
    }
    cout << '\n';
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