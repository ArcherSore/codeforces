#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pos[a[i] - 1].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        pos[b[i] - 1].push_back(i);
    }

    for (auto &v : pos) {
        sort(v.begin(), v.end());
    }

    int res = -1;
    for (auto v : pos) {
        if (v.size() <= 1) {
            continue;
        }
        int sz = v.size();
        int ls = v[sz - 1], lt = v[sz - 2];
        if (ls == lt) {
            res = max(res, ls);
        } else if (ls - 1 == lt) {
            if (a[ls] == a[lt] || b[ls] == b[lt]) {
                res = max(res, lt);
            } else {
                for (int i = sz - 3; i >= 0; i--) {
                    if (v[i] != lt) {
                        res = max(res, v[i]);
                        break;
                    }
                }
            }
        } else {
            res = max(res, lt);
        }
    }

    cout << res + 1 << '\n';
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