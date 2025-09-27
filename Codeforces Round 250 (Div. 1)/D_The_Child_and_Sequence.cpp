#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e18;

template<class Info>
struct SegmentTree {
    int n;
    vector<Info> info;
    SegmentTree() : n(0) {}
    template<class T>
    SegmentTree(vector<T> init_) {
        init(init_);
    }
    template<class T>
    void init(vector<T> init_) {
        // for (auto [s, x] : init_) {
        //     cerr << s << ' ' << x << '\n'; 
        // }
        // cerr << "-----------\n";
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
        // for (auto [s, x] : info) {
        //     cerr << s << ' ' << x << '\n';
        // }
        // cerr << "----------------\n";
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, ll mod) {
        info[p].apply(mod);
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
        if (r <= x || l >= y) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, ll mod) {
        if (r <= x || l >= y || info[p].mx < mod) {
            return;
        }
        if (r - l == 1) {
            apply(p, mod);
            return;
        }
        int m = (l + r) / 2;
        rangeApply(2 * p, l, m, x, y, mod);
        rangeApply(2 * p + 1, m, r, x, y, mod);
        pull(p);
    }
    void rangeApply(int l, int r, ll mod) {
        return rangeApply(1, 0, n, l, r, mod);
    }
};

struct Info {
    ll sum, mx;
    Info() : sum(0), mx(-inf) {}
    Info(ll x) : sum(x), mx(x) {}
    void apply(ll mod) & {
        mx %= mod;
        sum = mx;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    c.sum = a.sum + b.sum;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Info> v(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v[i] = Info(x);
    }
    // for (auto [s, x] : v) {
    //     cerr << s << ' ' << x << '\n';
    // }
    // cerr << "----------\n";
    SegmentTree<Info> sg(v);
    // for (int i = 0; i < n; i++) {
    //     cerr << sg.rangeQuery(i, i + 1).sum << ' ' << sg.rangeQuery(i, i + 1).mx << '\n';
    // }
    // cerr << '\n';
    while (m--) {
        int opt, l, r, x;
        cin >> opt;
        if (opt == 1) {
            cin >> l >> r;
            l--, r--;
            cout << sg.rangeQuery(l, r + 1).sum << '\n';
        } else if (opt == 2) {
            cin >> l >> r >> x;
            l--, r--;
            sg.rangeApply(l, r + 1, x);
        } else {
            cin >> l >> x;
            l--;
            sg.modify(l, Info(x));
        }
        // for (int i = 0; i < n; i++) {
        //     cerr << sg.rangeQuery(i, i + 1).sum << ' ' << sg.rangeQuery(i, i + 1).mx << '\n';
        // }
        // cerr << '\n';
    }

    return 0;
}