#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    SegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(vector(n_, v_));
    }
    template<class T>
    void init(vector<T> init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
};

struct Info {
    int x;

    Info() : x(0) {}
    Info(int v) : x(v) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.x = gcd(a.x, b.x);
    return c;
}

void solve() {
    int n, q;
    cin >> n >> q;
    if (n == 1) {
        int x;
        cin >> x;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << 0 << ' ';
        }
        cout << '\n';
        return;
    }
    vector<int> v(n - 1);
    int pre = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (pre != -1) {
            v[i - 1] = abs(x - pre);
        }
        pre = x;
    }

    SegmentTree<Info> seg(v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << seg.rangeQuery(l, r).x << ' ';
    }
    cout << '\n';
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