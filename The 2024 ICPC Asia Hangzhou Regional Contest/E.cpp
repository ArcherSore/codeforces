#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

struct Seg {
    int l, r, id;
    bool operator>(const Seg &o) const {
        return r < o.r;
    } 
};

void solve() {
    int n, f;
    cin >> n >> f;
    int mxr = 0;
    ll res = 0;
    vector<Seg> v(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        mxr = max(mxr, r);
        res += r - l;
        v[i] = {l, r, i + 1};
    }
    sort(v.begin(), v.end(), [](const Seg &a, const Seg &b) {
        return a.l < b.l;
    });
    
    int p = 0;
    priority_queue<Seg, vector<Seg>, greater<>> pq;
    vector<int> vis(n + 1), ord;
    while (f < mxr) {
        while (p < n && v[p].l <= f) {
            pq.push(v[p]);
            p++;
        }
        if (!pq.empty()) {
            auto [tl, tr, tid] = pq.top();
            if (tr > f) {
                f = tr;
                vis[tid] = 1;
                ord.push_back(tid);
                pq.pop();
                continue;
            }
        }
        
        int nl = v[p].l;
        // while (p < n && v[p].l == nl) {
        //     pq.push(v[p]);
        //     p++;
        // }
        res += nl - f;
        f = nl;
    }

    sort(v.begin(), v.end(), [](const Seg &a, const Seg &b) {
        return a.r > b.r;
    });
    for (int i = 0; i < n; i++) {
        if (vis[v[i].id]) {
            continue;
        }
        ord.push_back(v[i].id);
    }

    cout << res << '\n';
    for (auto x : ord) {
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