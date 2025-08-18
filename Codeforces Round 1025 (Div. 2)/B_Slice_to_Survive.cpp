#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int work(int x) {
    int res = 0;
    int p = 1;
    while (p < x) {
        p <<= 1;
        res++;
    }
    return res;
}

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int r1 = work(n), c1 = work(m);
    int r2 = 1 + work(min(a, n - a + 1));
    int c2 = 1 + work(min(b, m - b + 1));

    int ans = min(r2 + c1, c2 + r1);
    cout << ans << '\n';
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