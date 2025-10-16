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
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
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
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
};

struct Tag {
    ll add;
    Tag() : add(-1) {}
    Tag(ll a) : add(a) {}
    void apply(const Tag &v) & {
        if (v.add != -1) {
            if (add != -1) {
                add &= v.add;
            } else {
                add = v.add;
            }
        }
    }
};

struct Info {
    ll val, mask;
    int len;
    Info() : val(-1), mask(0), len(0) {}
    Info(ll x) : val(x), mask(~x), len(1) {}
    void apply(const Tag &v) & {
        if (v.add != -1) {
            val &= v.add;
            mask = (mask & v.add) | (len == 1 ? ~v.add : 0);
        }
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.val = a.val & b.val;
    c.mask = (a.val & b.mask) | (b.val & a.mask);
    c.len = a.len + b.len;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<Info> a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = Info(x);
    }

    SegmentTree<Info, Tag> sg(a);
    while (q--) {
        int opt, l, r, s;
        ll x;
        cin >> opt;
        if (opt == 1) {
            cin >> l >> r >> x;
            l--, r--;
            sg.rangeApply(l, r + 1, Tag(x));
        } else if (opt == 2) {
            cin >> s >> x;
            s--;
            sg.modify(s, Info(x));
        } else {
            cin >> l >> r;
            l--, r--;
            auto [val, mask, len] = sg.rangeQuery(l, r + 1);
            int pos = -1;
            for (int i = 62; i >= 0; i--) {
                if (mask >> i & 1) {
                    pos = sg.findFirst(l, r + 1, [&](const Info &v) {
                        return (v.val >> i & 1) == 0;
                    });
                    break;
                }
            }
            if (pos != -1) {
                ll rem = sg.rangeQuery(pos, pos + 1).val;
                val |= (mask & ~rem);
            }
            cout << val << '\n';
        }
    }

    return 0;
}