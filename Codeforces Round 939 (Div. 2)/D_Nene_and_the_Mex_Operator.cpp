#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> b(n); // choose or not
    int mx = 0;
    vector<int> best;
    auto work = [&]() -> int {
        int cnt = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                sum += cnt * cnt + a[i];
                cnt = 0;
            } else {
                cnt++;
            }
        }
        if (cnt) {
            sum += cnt * cnt;
        }
        return sum;
    };
    auto dfs = [&](auto &self, int lvl) -> void {
        if (lvl == n) {
            int scr = work();
            if (scr > mx) {
                mx = scr;
                best = b;
            }
            return;
        }
        self(self, lvl + 1);
        b[lvl] = 1;
        self(self, lvl + 1);
        b[lvl] = 0;
    };
    dfs(dfs, 0);

    int pre = -1;
    vector<PII> opt;
    auto mex = [&](int l, int r) -> void {
        int x = 0;
        vector<int> v(a.begin() + l, a.begin() + r + 1);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (v[i] < x) {
                continue;
            } else if (v[i] == x) {
                x++;
            } else {
                break;
            }
        }
        
        for (int i = l; i <= r; i++) {
            a[i] = x;
        }
    };
    auto recv = [&](auto &self, int l, int r) -> void {
        // make [l, r] all 0
        for (int i = l; i <= r; i++) {
            if (a[i] != 0) {
                opt.push_back({i, i});
                a[i] = 0;
            }
        }
        if (l == r) {
            opt.push_back({l, r});
            mex(l, r);
            return;
        }
        for (int i = r - 1; i >= l; i--) {
            self(self, l, i);
        }
        opt.push_back({l, r});
        mex(l, r);
    };

    for (int i = 0; i < n; i++) {
        if (best[i] == 0) {
            if (pre != -1) {
                recv(recv, pre, i - 1);
            }
            pre = -1;
        } else {
            if (pre == -1) {
                pre = i;
            }
        }
    }
    if (pre != -1) {
        recv(recv, pre, n - 1);
    }

    cout << mx << ' ' << opt.size() << '\n';
    for (auto [l, r] : opt) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}