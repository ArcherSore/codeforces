#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (min(a, c) >= min(b, d)) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
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