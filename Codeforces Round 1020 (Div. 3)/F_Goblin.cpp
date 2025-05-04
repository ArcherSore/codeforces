#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int lst = -1;
    LL up = 0, dn = 0;
    vector<LL> u, d;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (lst == -1) {
                lst = i;
            }
            up += i;
            dn += n - i - 1;
        } else {
            if (lst != -1) {
                u.push_back(up);
                d.push_back(dn);
            }
            u.push_back(-1);
            d.push_back(-1);
            lst = -1;
            up = dn = 0;
        }
    }
    if (lst != -1) {
        u.push_back(up);
        d.push_back(dn);
    }

    LL res = 0;
    for (int i = 0; i < u.size(); i++) {
        if (u[i] != -1) {
            res = max({res, u[i], d[i]});
        } else {
            LL tot = 1;
            if (i != 0 && d[i - 1] != -1) {
                tot += d[i - 1];
            }
            if (i != u.size() - 1 && u[i + 1] != -1) {
                tot += u[i + 1];
            }
            res = max(res, tot);
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