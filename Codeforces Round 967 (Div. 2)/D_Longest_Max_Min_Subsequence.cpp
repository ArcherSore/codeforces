#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

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
    int mx, mn;
    Info() : mx(0), mn(INF) {}
    Info(int x) : mx(x), mn(x) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    c.mx = max(a.mx, b.mx);
    c.mn = min(a.mn, b.mn);
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<vector<int>> num(n + 1);
    vector<int> cnt(n + 1);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        num[v[i]].push_back(i);
        cnt[v[i]]++;
        s.insert(v[i]);
    }
    
    SegmentTree<Info> seg(v);
    int st = 0, ed = 0;
    vector<int> res;
    while (res.size() < s.size()) {
        while (ed < n && cnt[v[ed]] != 1) {
            cnt[v[ed]]--;
            ed++;
        }
        if (res.size() % 2) {
            // 填的是偶数
            int mn = seg.rangeQuery(st, ed + 1).mn;
            res.push_back(mn);
            int nxt = lower_bound(num[mn].begin(), num[mn].end(), st) - num[mn].begin();
            st = num[mn][nxt] + 1;
            for (auto pos : num[mn]) {
                seg.modify(pos, Info());
            }
            cnt[mn] = 0;
        } else {
            int mx = seg.rangeQuery(st, ed + 1).mx;
            res.push_back(mx);
            int nxt = lower_bound(num[mx].begin(), num[mx].end(), st) - num[mx].begin();
            st = num[mx][nxt] + 1;
            for (auto pos : num[mx]) {
                seg.modify(pos, Info());
            }
            cnt[mx] = 0;
        }
    }

    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
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