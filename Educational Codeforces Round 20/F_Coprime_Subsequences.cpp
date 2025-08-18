#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll mod = 1e9 + 7;

ll fpow(ll a, ll x) {
    ll res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll V = *max_element(v.begin(), v.end());
    vector<ll> freq(V + 1);
    for (ll x : v) {
        freq[x]++;
    }
    vector<ll> dp(V + 1);
    for (ll i = V; i; i--) {
        ll j = 1;
        ll sdp = 0, se = 0;
        while (i * j <= V) {
            if (j > 1) {
                sdp = (sdp + dp[i * j]) % mod;
            }
            se = (se + freq[i * j]) % mod;
            j++;
        }
        dp[i] = (fpow(2, se) - 1 - sdp + mod) % mod;
    }
    cout << dp[1];
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