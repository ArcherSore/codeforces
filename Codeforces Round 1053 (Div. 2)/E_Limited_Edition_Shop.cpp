#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll inf = 1e18;

template<class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree() : n(0) {}
    SegmentTree(int n_) {
        init(n_);
    }
    void init(int n_) {
        n = n_;
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
        function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = Info(0);
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
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
    void modify(int x, const Info &v) {
        modify(1, 0, n, x, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (r <= x || l >= y) {
            return Info();
        }
        if (x <= l && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (r <= x || l >= y) {
            return;
        }
        if (x <= l && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        rangeApply(1, 0, n, l, r, v);
    }
};

struct Tag {
    ll add;
    Tag() : add(0) {}
    Tag(ll a) : add(a) {}
    void apply(const Tag &v) & {
        add += v.add;
    }
};

struct Info {
    ll mx;
    Info() : mx(-inf) {}
    Info(ll x) : mx(x) {}
    void apply(const Tag &v) & {
        mx += v.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    return Info(max(a.mx, b.mx));
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<int> a(n), b(n);
    vector<int> pos(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
        pos[b[i]] = i;
    }

    SegmentTree<Info, Tag> sg(n + 1);
    for (int i = 0; i < n; i++) {
        int p = pos[a[i]] + 1;
        ll mx = max(sg.rangeQuery(0, p).mx, sg.rangeQuery(p, p + 1).mx);
        sg.modify(p, Info(mx));
        sg.rangeApply(0, p, Tag(v[a[i]]));
    }
    ll res = sg.rangeQuery(0, n + 1).mx;
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