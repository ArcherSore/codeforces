#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

void solve() {
    int n, k;
    cin >> n;
    if (n == 4) {
        cout << -1 << '\n';
        return;
    }
    k = 2 * n / 3 + 1;
    int rest = n - k, tot = k - 1;
    int useless = rest + (k + 1) / 2 - tot;
    int use = rest - useless;

    for (int i = 2; i <= k; i++) {
        cout << i - 1 << ' ' << i << '\n'; 
    }
    for (int i = k + 1; i <= k + use; i++) {
        cout << k - 1 << ' ' << i << '\n';
    }
    for (int i = k + use + 1; i <= n; i++) {
        cout << k - 2 << ' ' << i << '\n';
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

// 2:42:52 1