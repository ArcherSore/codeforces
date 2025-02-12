#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

template <typename T>
struct Fenwick {
    int n;
    vector<T> a;
    
    Fenwick(int n_ = 0) {
        init(n_);
    }
    
    void init(int n_) {
        n = n_;
        a.assign(n, T{});
    }
    
    void add(int x, const T &v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] = a[i - 1] + v;
        }
    }
    
    T sum(int x) {
        T ans{};
        for (int i = x; i > 0; i -= i & -i) {
            ans = ans + a[i - 1];
        }
        return ans;
    }
    
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
    
    int select(const T &k) {
        int x = 0;
        T cur{};
        for (int i = 1 << __lg(n); i; i /= 2) {
            if (x + i <= n && cur + a[x + i - 1] < k) {
                x += i;
                cur = cur + a[x - 1];
            }
        }
        return x;
    }
};

struct Point {
    int x, y;
};

bool check(vector<Point> &v, int k, int m, vector<int> &tx, int &x, int &y) {
    if (k == 0) {
        x = 0, y = 0;
        return true;
    }

    int n = v.size();
    Fenwick<int> fenwU(m), fenwL(m);
    for (int i = 0; i < n; i++) {
        fenwU.add(v[i].x, 1);
    }
    vector<int> cy;
    cy.push_back(v[0].y);
    for (int i = 1; i < n; i++) {
        if (v[i].y != v[i - 1].y) {
            cy.push_back(v[i].y);
        }
    }

    int p = 0, Lcnt = 0;
    for (int y0 : cy) {
        // move all points below y0 to Lower side
        while (p < n && v[p].y < y0) {
            fenwU.add(v[p].x, -1);
            fenwL.add(v[p].x, 1);
            p++;
            Lcnt++;
        }
        int Ucnt = n - Lcnt;
        if (Lcnt < 2 * k || Ucnt < 2 * k) {
            continue;
        }
        
        int Ul = fenwU.select(k), Ur = fenwU.select(Ucnt - k + 1);
        int Ll = fenwL.select(k), Lr = fenwL.select(Lcnt - k + 1);

        // if (Ul == m || Ur == m || Ll == m || Lr == m) {
        //     continue;
        // }

        int l = max(Ul, Ll), r = min(Ur, Lr);
        if (l > r) {
            continue;
        }
        int candx = tx[l] + 1;
        if (candx  <= tx[r]) {
            x = candx, y = y0;
            return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> v(n);
    vector<int> tx(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
        tx[i] = v[i].x;
    }
    // discrete
    sort(tx.begin(), tx.end());
    tx.erase(unique(tx.begin(), tx.end()), tx.end());
    int m = tx.size();
    for (int i = 0; i < n; i++) {
        v[i].x = lower_bound(tx.begin(), tx.end(), v[i].x) - tx.begin();
    }
    sort(v.begin(), v.end(), [](const Point &a, const Point &b) {
        return a.y < b.y;
    });

    int l = -1, r = n / 4, mid;
    int res, bx, by;
    while (l < r) {
        mid = (l + r + 1) / 2;
        int x, y;
        if (check(v, mid, m, tx, x, y)) {
            l = mid;
            res = mid;
            bx = x, by = y;
        } else {
            r = mid - 1;
        }
    }
    cout << res << '\n' << bx << ' ' << by << '\n';
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