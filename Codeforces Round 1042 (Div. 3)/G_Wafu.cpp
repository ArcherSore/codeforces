#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;

vector<ll> mul(32);

void init() {
    mul[1] = 1, mul[2] = 2;
    for (int i = 3; i < 32; i++) {
        mul[i] = i;
        for (int j = 1; j < i; j++) {
            mul[i] = mul[i] * mul[j] % mod;
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    set<ll> s;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        s.insert(x);
    }

    ll res = 1;
    while (true) {
        if (k == 0) {
            break;;
        }
        // 完全删除
        while (k) {
            ll fir = *s.begin();
            if (fir > 31 || k < (1LL << fir - 1)) {
                break;
            }
            s.erase(s.begin());
            k -= (1LL << fir - 1);
            res = res * mul[fir] % mod;
        }
        if (k == 0) {
            break;
        }
        // 剩余的轮数不足以完全删除 fir
        ll fir = *s.begin();
        s.erase(s.begin());
        k -= 1;
        res = res * fir % mod;
        ll tot = 0;
        for (int i = 1; i < fir && tot <= k; i++) {
            s.insert(i);
            tot += (1LL << i - 1);
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}