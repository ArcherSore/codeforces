#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int N = 1e5;

vector<int> minp(N + 1), primes;
vector<vector<int>> fac(N + 1);

void init() {
    for (int i = 2; i <= N; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (i * p > N) {
                break;
            }
            minp[i * p] = p;
            if (minp[i] == p) {
                break;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        int x = i;
        while (x > 1) {
            fac[i].push_back(minp[x]);
            x /= minp[x];
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> jump(n);
    map<int, int> freq;
    int ri = 0;
    for (int le = 0; le < n; le++) {
        int flag = 0;
        while (ri < n) {
            for (auto p : fac[a[ri]]) {
                if (freq[p] > 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                break;
            }
            for (auto p : fac[a[ri]]) {
                freq[p]++;
            }
            ri++;
        }
        jump[le] = ri;
        for (auto p : fac[a[le]]) {
            freq[p]--;
        }
    }

    const int LOG = __lg(n) + 1;
    vector<vector<int>> st(n, vector<int> (LOG, n));
    for (int i = 0; i < n; i++) {
        st[i][0] = jump[i];
    }
    for (int k = 0; k < LOG - 1; k++) {
        for (int i = 0; i < n; i++) {
            if (st[i][k] == n) {
                st[i][k + 1] = n;
            } else {
                st[i][k + 1] = st[st[i][k]][k];
            }
        }
    }

    auto query = [&](int l, int r) -> int {
        int cur = l, res = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            if (cur < n && st[cur][i] <= r) {
                cur = st[cur][i];
                res += (1 << i);
            }
        }
        if (cur <= r) {
            res += 1;
        }
        return res;
    };

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << query(l, r) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    init();

    while (T--) {
        solve();
    }

    return 0;
}