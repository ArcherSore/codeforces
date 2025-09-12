#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Seg {
    ll x, y, len;
    bool operator<(const Seg &other) const {
        return len < other.len;
    }
};

void solve() {
    int n;
    cin >> n;
    ll base = 0;
    vector<Seg> seg(n);
    ll sumx = 0, sumy = 0;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        seg[i] = {x, y, x + y};
        base += y - x;
        sumx += x, sumy += y;
    }
    sort(seg.begin(), seg.end());
    ll mnlen = 0, mxlen = 0;
    for (int i = 0; i < n / 2; i++) {
        mnlen += seg[i].len;
    }
    for (int i = n / 2; i < n; i++) {
        mxlen += seg[i].len;
    }
    if (n % 2 == 0) {
        ll res = (sumy - sumx + mxlen - mnlen) / 2;
        // cerr << res << '\n';
        cout << res + base << '\n';
        return;
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        // the i-th segment is unchosen
        ll tmnlen, tmxlen;
        if (i < n / 2) {
            tmnlen = mnlen + seg[n / 2].len - seg[i].len;
            tmxlen = mxlen - seg[n / 2].len;
        } else {
            tmnlen = mnlen;
            tmxlen = mxlen - seg[i].len;
        }
        res = max(res, ((sumy - seg[i].y) - (sumx - seg[i].x) + tmxlen - tmnlen) / 2);
        // cerr << ((sumy - seg[i].y) - (sumx - seg[i].x) + tmxlen - tmnlen) / 2 << '\n';
    }
    cout << res + base << '\n';
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