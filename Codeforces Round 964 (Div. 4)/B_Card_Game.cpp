#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int sc(int a, int b) {
    if (a > b) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int res = 0;
    if (sc(a, c) + sc(b, d) > 0) {
        res++;
    }
    if (sc(a, d) + sc(b, c) > 0) {
        res++;
    }
    if (sc(b, c) + sc(a, d) > 0) {
        res++;
    }
    if (sc(b, d) + sc(a, c) > 0) {
        res++;
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