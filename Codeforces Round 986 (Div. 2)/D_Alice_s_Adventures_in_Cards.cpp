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
    int x, id;
    Info() : x(0), id(0) {}
    Info(int _x, int _id) : x(_x), id(_id) {}
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    if (a.x > b.x) {
        c = a;
    } else {
        c = b;
    }
    return c;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> p(3, vector<int> (n));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> p[i][j];
        }
    }
    SegmentTree<Info> Q(n), K(n), J(n);
    Q.modify(0, Info(p[0][0], 0));
    K.modify(0, Info(p[1][0], 0));
    J.modify(0, Info(p[2][0], 0));
    vector<pair<char, int>> pre(n, {'$', -1});
    for (int j = 1; j < n; j++) {
        int flag = 0;
        auto iq = Q.rangeQuery(0, j);
        auto ik = K.rangeQuery(0, j);
        auto ij = J.rangeQuery(0, j);
        if (iq.x > p[0][j]) {
            pre[j] = {'q', iq.id};
            flag = 1;
        } else if (ik.x > p[1][j]) {
            pre[j] = {'k', ik.id};
            flag = 1;
        } else if (ij.x > p[2][j]) {
            pre[j] = {'j', ij.id};
            flag = 1;
        }

        if (flag) {
            Q.modify(j, Info(p[0][j], j));
            K.modify(j, Info(p[1][j], j));
            J.modify(j, Info(p[2][j], j));
        } else {
            Q.modify(j, Info(0, j));
            K.modify(j, Info(0, j));
            J.modify(j, Info(0, j));
        }
        if (j == n - 1 && !flag) {
            cout << "NO\n";
            return;
        }
    }
    vector<pair<char, int>> res;
    int pos = n - 1;
    while (pre[pos].second != -1) {
        res.push_back({pre[pos].first, pos + 1});
        pos = pre[pos].second;
    }
    reverse(res.begin(), res.end());
    cout << "YES\n" << res.size() << '\n';
    for (auto [c, x] : res) {
        cout << c << ' ' << x << '\n';
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