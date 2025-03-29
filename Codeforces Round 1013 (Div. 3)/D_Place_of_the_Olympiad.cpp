#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int col;
    if (n >= k) {
        col = 1;
    } else {
        col = max(k / n, (k + n - 1) / n);
    }

    int avai = m - col;
    // cout << avai << ' ' << m << ' ';
    cout << m / (avai + 1) << '\n';
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