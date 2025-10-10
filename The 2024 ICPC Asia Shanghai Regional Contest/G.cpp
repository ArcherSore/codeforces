#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;
const ll inf = 4e18;

ll floor(ll a, ll b) {
    ll res = a / b;
    if ((a ^ b) < 0 && a % b) {
        res -= 1;
    }
    return res;
}

ll ceil(ll a, ll b) {
    ll res = a / b;
    if ((a ^ b) > 0 && a % b) {
        res += 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (auto &x : c) cin >> x;
    sort(c.begin(), c.end());

    ll le = -inf, ri = inf, mid;
    ll res = -inf;
    auto check = [&](ll y) -> bool {
        int cnt = 0;
        vector<ll> xpos, xneg;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                xpos.push_back(ceil(y - b[i], a[i]));
            } else if (a[i] < 0) {
                xneg.push_back(floor(y - b[i], a[i]));
            } else {
                if (b[i] >= y) {
                    cnt++;
                }
            }
        }
        sort(xpos.begin(), xpos.end(), greater<> ());
        sort(xneg.begin(), xneg.end());
        
        int l = 0, r = n - 1;
        for (auto x : xpos) {
            if (x <= c[r]) {
                cnt++;
                r--;
            }
        }
        for (auto x : xneg) {
            if (x >= c[l]) {
                cnt++;
                l++;
            }
        }

        return cnt >= (n + 1) / 2;
    };
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (check(mid)) {
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