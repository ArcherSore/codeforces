#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int l = 1, r = 1000, a, b;
    int area;
    auto check = [&]() -> int {
        if (a * b == area) {
            return 0;
        } else if (a * (b + 1) == area) {
            return 1;
        } else {
            return 2;
        }
    };
    int ans = -1;
    while (l <= r) {
        a = l + (r - l) / 3;
        b = r - (r - l) / 3;
        cout << "? " << a << ' ' << b << endl;
        cin >> area;
        int res = check();
        if (res == 0) {
            l = b + 1;
        } else if (res == 1) {
            ans = b;
            l = a + 1, r = b - 1;
        } else {
            ans = a;
            r = a - 1;
        }
    }
    cout << "! " << ans << endl;
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