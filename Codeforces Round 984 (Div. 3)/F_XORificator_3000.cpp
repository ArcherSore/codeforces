#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1LL << 60;

void solve() {
    LL l, r, i, k;
    cin >> l >> r >> i >> k;
    
    vector<LL> bit(62);
    auto work = [&](LL x, int offset) -> void {
        int p = 0;
        while (x >> p) {
            bit[p + offset] += (x + 1) / (1LL << p + 1) * (1LL << p) + max(0LL, (x + 1) % (1LL << p + 1) - (1LL << p));
            bit[p + offset] &= 1;
            p++;
        }
    };

    work(max(l - 1, 0LL), 0);
    work(r, 0);

    LL cnt = 0;
    LL le = 0, ri = INF >> i, mid;
    while (le < ri) {
        mid = (le + ri) / 2;
        if (((mid << i) | k) > r) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }
    // cout << ri << '\n';
    work(max(ri - 1, 0LL), i);
    cnt = ri;

    le = 0, ri = INF >> i, mid;
    while (le < ri) {
        mid = (le + ri) / 2;
        if (((mid << i) | k) >= l) {
            ri = mid;
        } else {
            le = mid + 1;
        }
    }
    // cout << le << '\n';
    work(max(le - 1, 0LL), i);
    cnt -= le;
    
    // cout << cnt << '\n';
    if (cnt & 1) {
        for (int p = 0; p < 61; p++) {
            bit[p] += (k >> p) & 1;
            bit[p] &= 1;
        }
    }

    LL res = 0;
    for (int p = 0; p < 61; p++) {
        res |= ((bit[p] & 1LL) << p);
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