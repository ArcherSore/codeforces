#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    auto all1 = [&]() -> bool {
        for (auto x : v) {
            if (x == 0) {
                return false;
            }
        }
        return true;
    };
    if (all1()) {
        cout << 1 << '\n';
        cout << 1 << ' ' << n << '\n';
    } else if (v[0] != 0) {
        cout << 2 << '\n';
        cout << 2 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else if (v.back() != 0) {
        cout << 2 << '\n';
        cout << 1 << ' ' << n - 1 << '\n';
        cout << 1 << ' ' << 2 << '\n';
    } else {
        cout << 3 << '\n';
        cout << 3 << ' ' << n << '\n';
        cout << 1 << ' ' << 2 << '\n';
        cout << 1 << ' ' << 2 << '\n';
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