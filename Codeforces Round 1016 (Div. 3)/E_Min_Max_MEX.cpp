#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> b(a);
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    vector<int> c(a);
    for (auto &x : c) {
        x = lower_bound(b.begin(), b.end(), x) - b.begin();
    }
    int d = b.size();
    
    int le = 0, ri = d, mid;
    int res = 0;
    auto check = [&]() -> bool {
        int cnt = 0, tot = 0;
        vector<int> vis(d);
        for (int i = 0; i < n; i++) {
            if (a[i] < mid && vis[c[i]] == cnt) {
                vis[c[i]]++;
                tot++;
            }
            if (tot == mid) {
                cnt++;
                tot = 0;
            }
        }
        return cnt >= k;
    };
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (check()) {
            res = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }
    }
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