#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

template<class Info, class Tag>
struct SegmentTree {
    int n;
    vector<Info> info;
    vector<Tag> tag;
    SegmentTree() : n(0) {}
    SegmentTree(vector<Info> &init_) {
        init(init_);
    }
    void init(vector<Info> &init_) {
        n = init_.size();
        info.assign(4 << __lg(n), Info());
        tag.assign(4 << __lg(n), Tag());
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
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
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
};

struct Tag {
    ll val;
    Tag() : val(-1) {}
    Tag(ll val_) : val(val_) {}
    void apply(const Tag &v) & {
        if (v.val != -1) {
            val = v.val;
        }
    }
};

struct Info {
    ll val;
    bool same;
    Info () : val(0), same(true) {}
    Info(ll val_) : val(val_), same(true) {}
    void apply(const Tag &v) & {
        if (v.val != -1) {
            val = v.val;
            same = true;
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.val = gcd(a.val, b.val);
    c.same = (a.same && b.same && a.val == b.val);
    return c;
}

const int N = 2e5;
vector<int> d(N + 1);

void init() {
    d[0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            d[j]++;
        }
    }
}

int work(ll x) {
    return d[x];
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    int st = 0, len = 1;
    map<int, int> seg; // start from index i, with its length
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            len++;
        } else {
            seg[st] = len;
            st = i, len = 1;
        }
    }
    seg[st] = len;

    vector<Info> v(n);
    for (auto [s, l] : seg) {
        for (int i = s; i < s + l; i++) {
            v[i] = Info(l);
        }
    }
    SegmentTree<Info, Tag> tr(v);
    auto getAns = [&]() -> int {
        int lst = (*seg.rbegin()).first;
        if (lst == 0) {
            // only one segments
            return n;
        }
        return work(tr.rangeQuery(0, lst).val);
    };
    cout << getAns() << '\n';

    auto split = [&](int p) -> void {
        if (p < 0 || p >= n - 1) {
            return;
        }
        auto it = seg.upper_bound(p);
        it--;
        auto [s, l] = *it;
        int e = s + l - 1; // [s, e], len is l
        if (s > p || p >= e) {
            return;
        }
        int lenl = p - s + 1, lenr = e - p;

        seg.erase(it);
        seg[s] = lenl;
        seg[p + 1] = lenr;
        tr.rangeApply(s, p + 1, Tag(lenl));
        tr.rangeApply(p + 1, s + l, Tag(lenr));
    };
    auto merge = [&](int p) -> void {
        if (p < 0 || p >= n - 1) {
            return;
        }
        auto itr = seg.find(p + 1);
        if (itr == seg.end()) {
            return;
        }
        auto itl = prev(itr);
        auto [sl, lenl] = *itl;
        auto [sr, lenr] = *itr;

        seg.erase(itl);
        seg.erase(itr);
        seg[sl] = lenl + lenr;

        tr.rangeApply(sl, sr + lenr, Tag(lenl + lenr));
    };

    while (q--) {
        int p;
        ll v;
        cin >> p >> v;
        p--;

        // no changes
        if (a[p] == v) {
            cout << getAns() << '\n';
            continue;
        }

        bool oldl = (p > 0 && a[p - 1] > a[p]);
        bool oldr = (p + 1 < n && a[p] > a[p + 1]);
        bool newl = (p > 0 && a[p - 1] > v);
        bool newr = (p + 1 < n && v > a[p + 1]);
        a[p] = v;

        if (oldl != newl) {
            if (newl) {
                split(p - 1);
            } else {
                merge(p - 1);
            }
        }
        if (oldr != newr) {
            if (newr) {
                split(p);
            } else {
                merge(p);
            }
        }

        cout << getAns() << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}