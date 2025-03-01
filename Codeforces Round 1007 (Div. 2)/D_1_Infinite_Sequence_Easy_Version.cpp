#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    LL l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] ^ a[i];
    }

    auto work = [&](auto &self, LL x) -> LL {
        if (x <= n) {
            return pre[x - 1];
        }
        LL res = pre[n - 1];
        if ((n + 1) % 2) {
            res ^= self(self, (n + 1) / 2);
        }
        if (x % 2 == 0) {
            res ^= self(self, x / 2);
        }
        return res;
    };

    LL res;
    if (l <= n) {
        res = a[l - 1];
    } else {
        res = work(work, l / 2);
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