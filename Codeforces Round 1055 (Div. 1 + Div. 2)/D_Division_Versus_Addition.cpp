#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

struct ST {
    int n, LOG;
    vector<vector<int>> st;
    ST() : n(0) {}
    ST(vector<int> &a) {
        init(a);
    }
    void init(vector<int> &a) {
        n = a.size();
        LOG = __lg(n) + 1;
        st.assign(LOG, vector<int> (n, -inf));

        for (int i = 0; i < n; i++) {
            st[0][i] = a[i];
        }
        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i + (1 << k) - 1 < n; i++) {
                st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
            }
        }
    }
    int query(int l, int r) {
        int k = __lg(r - l);
        return max(st[k][l], st[k][r - (1 << k)]);
    }
};

int work1(int x) {
    int i, cnt = 0;
    for (i = 0; x > 1; i++) {
        if (i & 1) {
            x += 1;
        } else {
            x >>= 1;
            cnt++;
        }
    }
    return cnt;
}

int work2(int x) {
    int i, cnt = 0;
    for (i = 0; x > 1; i++) {
        if (i & 1) {
            x >>= 1;
            cnt++;
        } else {
            x += 1;
        }
    }
    return cnt;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n), c(n), d(n);
    vector<int> pre(n + 1), ones(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = work1(a[i]);
        c[i] = work2(a[i]);
        pre[i + 1] = pre[i] + c[i];
        d[i] = c[i] - b[i];
        ones[i + 1] = ones[i] + d[i];
    }
    // ST st(d);

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        // cerr << pre[r + 1] - pre[l] << '\n';
        cout << (pre[r + 1] - pre[l]) - (ones[r + 1] - ones[l] + 1) / 2 << '\n';
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