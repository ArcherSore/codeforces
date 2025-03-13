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
    Info() : x(-1) {}
    Info(int _x) : x(_x) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.x = max(a.x, b.x);
    return c;
}

struct Seg {
    int id;
    int l, r;
    int dr;
    int ans;
};

void solve() {
    int n;
    cin >> n;
    vector<Seg> v(n);
    vector<int> tr(n);
    map<PII, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> v[i].l >> v[i].r;
        tr[i] = v[i].r;
        v[i].id = i;
        cnt[{v[i].l, v[i].r}]++;
    }
    sort(tr.begin(), tr.end());
    tr.erase(unique(tr.begin(), tr.end()), tr.end());
    int m = tr.size(); // the size of discreted r
    for (int i = 0; i < n; i++) {
        v[i].dr = lower_bound(tr.begin(), tr.end(), v[i].r) - tr.begin();
    }
    sort(v.begin(), v.end(), [](const Seg &a, const Seg &b) {
        if (a.l != b.l) {
            return a.l < b.l;
        }
        return a.dr > b.dr;
    });

    SegmentTree<Info> seg(m);
    set<int> r;
    const int INF = 2e9;
    r.insert(INF);

    for (int i = 0; i < n; i++) {
        int p = v[i].dr;
        int mx_l = seg.rangeQuery(p, m).x;
        int mn_r = *r.lower_bound(v[i].r);

        int res = 0;
        if (cnt[{v[i].l, v[i].r}] == 1 && mx_l != -1 && mn_r != INF) {
            res += v[i].l - mx_l;
            res += mn_r - v[i].r;
        }
        v[i].ans = res;
        if (v[i].l > seg.rangeQuery(p, p + 1).x) {
            seg.modify(p, Info(v[i].l));
        }
        r.insert(v[i].r);
    }

    sort(v.begin(), v.end(), [](const Seg &a, const Seg &b) {
        return a.id < b.id;
    });
    for (auto x : v) {
        cout << x.ans << '\n';
    }
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