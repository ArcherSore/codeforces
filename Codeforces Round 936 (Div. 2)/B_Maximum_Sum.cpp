// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int MOD = 1e9 + 7;

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
    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        tot = (tot + a[i]) % MOD;
    }
    LL sum = 0, tmp = 0;
    for (auto x : a) {
        if (tmp + x < 0) {
            sum = max(sum, tmp);
            tmp = 0;
        } else {
            tmp += x;
            sum = max(sum, tmp);
        }
    }
    sum %= MOD;
    // cout << "sum = " << sum << '\n';
    LL res = sum * (fpow(2, k) - 1) % MOD + tot;
    cout << (MOD + res) % MOD << '\n';
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