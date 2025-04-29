#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<int> minp, primes;
vector<LL> f;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.rbegin(), v.rend());
    vector<LL> pre(n);
    pre[0] = v[0];
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + v[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (pre[i] >= f[i + 1]) {
            res = i;
        } else {
            break;
        }
    }
    cout << n - res - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    sieve(7000000);
    f.push_back(0LL);
    for (auto p : primes) {
        f.push_back(p + f.back());
    }

    while (T--) {
        solve();
    }

    return 0;
}