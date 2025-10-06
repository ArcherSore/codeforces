#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3;
const ll mod = 998244353;

vector<ll> fac(N + 1);

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % mod;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int n;
    cin >> n;

    vector<ll> a(n);
    map<ll, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a.begin(), a.end());

    ll res = (cnt.size() == 1 ? 1 : 2);
    for (auto &[x, c] : cnt) {
        res = res * fac[c] % mod;
    }
    
    ll mn = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            mn += a[j] - a[i];
        }
    }
    cout << mn << ' ' << res;

    return 0;
}