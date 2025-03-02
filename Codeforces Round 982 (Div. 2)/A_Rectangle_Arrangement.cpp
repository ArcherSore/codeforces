#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> h(110);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        for (int i = 1; i <= a; i++) {
            h[i] = max(h[i], b);
        }
    }

    int res = 0;
    for (int i = 1; i <= 100; i++) {
        if (h[i] == 0) {
            break;
        }
        if (h[i] >= h[i - 1]) {
            res += 2 + 2 * (h[i] - h[i - 1]);
        } else {
            res += 2;
        }
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