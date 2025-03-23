#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 3e5;
vector<LL> f(N + 1);

const LL MOD = 1e9 + 7;

void init() {
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= N; i++) {
        f[i] = f[i - 1] + 2 * (i - 1) * f[i - 2] % MOD;
        f[i] %= MOD;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    while (k--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            n -= 1;
        } else {
            n -= 2;
        }
    }
    cout << f[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}