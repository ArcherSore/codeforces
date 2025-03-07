#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL MOD = 1e9 + 7;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        x >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), base(n), p(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        base[i] = a[i];
        while (base[i] % 2 == 0) {
            base[i] /= 2;
            p[i]++;
        }
    }
    auto cmp = [&](int i, int x) -> bool {
        return log(base[i]) + p[i] * log(2) >= log(x);
    };
    LL sum = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (st.empty()) {
            sum = (sum + a[i]) % MOD;
        } else {
            while (!st.empty() && cmp(i, base[st.top()])) {
                int id = st.top();
                st.pop();
                sum = (sum - base[id] * fpow(2, p[id]) % MOD + base[id]) % MOD;
                p[i] += p[id];
            }
            sum = (sum + base[i] * fpow(2, p[i]) % MOD) % MOD;
        }
        if (p[i] > 0) {
            st.push(i);
        }
        cout << (sum + MOD) % MOD << ' ';
    }
    cout << '\n';
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