#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int m = gcd(a, b);
    set<int> c;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        x %= m;
        c.insert(x);
    }
    
    int mx = *c.rbegin(), mn = *c.begin();
    int res = mx - mn;
    for (auto it = c.begin(); it != c.end(); it++) {
        auto tmp = it;
        tmp++;
        if (tmp == c.end()) {
            break;
        }
        int x = *it, nxt = *tmp;
        mx = x + m;
        mn = nxt;
        res = min(res, mx - mn);
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