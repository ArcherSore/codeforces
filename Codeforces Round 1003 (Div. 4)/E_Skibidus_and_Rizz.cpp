#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

bool check(string &s, int k) {
    int mx = 0, mn = 0;
    int scr = 0;
    for (auto c : s) {
        scr += (c == '0' ? -1 : 1);
        mx = max(mx, scr);
        mn = min(mn, scr);
    }
    return mx - mn == k;
}

void solve() {
    array<char, 2> ch = {'0', '1'};
    int n, m, k;
    cin >> n >> m >> k;
    if (n < m) {
        swap(n, m);
        swap(ch[0], ch[1]);
    }
    string res;
    while (n > 0 && m > 0) {
        if (n >= k) {
            res.append(k, ch[0]);
            n -= k;
        } else {
            res.append(n, ch[0]);
            n = 0;
        }
        if (m >= k) {
            res.append(k, ch[1]);
            m -= k;
        } else {
            res.append(m, ch[1]);
            m = 0;
        }
    }
    res.append(n, ch[0]);
    // cout << res << ' ';
    if (check(res, k)) {
        cout << res << '\n';
    } else {
        cout << -1 << '\n';
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