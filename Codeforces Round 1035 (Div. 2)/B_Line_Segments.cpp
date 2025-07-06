#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    LL x, y, a, b;
    cin >> x >> y >> a >> b;

    LL dist = (x - a) * (x - a) + (y - b) * (y - b);
    if (dist != 0) {
        LL tot = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            LL d;
            cin >> d;
            tot += d;
            mx = max(mx, d);
        }
        if (max(0LL, 2 * mx - tot) * max(0LL, 2 * mx - tot) <= dist && dist <= tot * tot) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        if (n == 1) {
            LL d;
            cin >> d;
            cout << "No\n";
        } else if (n > 2) {
            LL sum = 0;
            vector<int> d(n);
            for (auto &x : d) {
                cin >> x;
                sum += x;
            }
            sort(d.begin(), d.end());
            sum -= d.back();
            cout << (sum >= d.back() ? "Yes\n" : "No\n");
        } else {
            LL d1, d2;
            cin >> d1 >> d2;
            cout << (d1 == d2 ? "Yes\n" : "No\n");
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