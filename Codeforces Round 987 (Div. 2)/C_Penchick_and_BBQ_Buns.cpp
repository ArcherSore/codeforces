#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i <= n / 2; i++) {
            cout << i << ' ' << i << ' ';
        }
        cout << '\n';
    } else {
        if (n < 27) {
            cout << -1 << '\n';
            return;
        }
        vector<int> t = {1, 2, 2, 3, 3, 4, 4, 5, 5, 1, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 11, 12, 13, 13, 1, 12};
        int p = 14;
        while (t.size() < n) {
            t.push_back(p);
            t.push_back(p);
            p++;
        }
        for (auto x : t) {
            cout << x << ' ';
        }
        cout << '\n';
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