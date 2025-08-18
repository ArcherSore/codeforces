#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e5;
const LL MOD = 998244353;

vector<LL> f(N + 1);

void init() {
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
        f[i] = (f[i - 1] * 2) % MOD;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    for (auto &x : p) {
        cin >> x;
    }
    for (auto &x : q) {
        cin >> x;
    }

    vector<int> mp(n), mq(n);
    mp[0] = 0;
    for (int i = 1; i < n; i++) {
        if (p[i] > p[mp[i - 1]]) {
            mp[i] = i;
        } else {
            mp[i] = mp[i - 1];
        }
    }
    mq[0] = 0;
    for (int i = 1; i < n; i++) {
        if (q[i] > q[mq[i - 1]]) {
            mq[i] = i;
        } else {
            mq[i] = mq[i - 1];
        }
    }

    for (int i = 0; i < n; i++) {
        int x1 = max(p[mp[i]], q[i - mp[i]]);
        int y1 = min(p[mp[i]], q[i - mp[i]]);

        int x2 = max(p[i - mq[i]], q[mq[i]]);
        int y2 = min(p[i - mq[i]], q[mq[i]]);

        int cx, cy;
        if (x1 > x2 || (x1 == x2 && y1 > y2)) {
            cx = x1, cy = y1;
        } else {
            cx = x2, cy = y2;
        }

        LL res = (f[cx] + f[cy]) % MOD;
        cout << res << ' ';
    }
    cout << '\n';
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