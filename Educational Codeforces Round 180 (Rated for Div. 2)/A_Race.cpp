#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int a, x, y;
    cin >> a >>  x >> y;
    if (x > y) {
        swap(x, y);
    }
    if (x <= a && a <= y) {
        cout << "NO\n";
    }  else {
        cout << "YES\n";
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