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

void st(LL &a, LL &b, LL &c) {
    if (a > b) swap(a, b); 
    if (b > c) swap(b, c); 
    if (a > b) swap(a, b); 
}

vector<LL> get_fac(LL x) {
    vector<LL> fac;
    fac.push_back(1);
    for (LL i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            fac.push_back(i);
            if (i * i != x) {
                fac.push_back(x / i);
            }
        }
    }
    if (x != 1) {
        fac.push_back(x);
    }
    sort(fac.begin(), fac.end());
    return fac;
}

void solve() {
    LL a, b, c, k, ans = 0;
    cin >> a >> b >> c >> k;
    st(a, b, c);

    vector<LL> factors = get_fac(k);
    // cout << factors.size() << '\n';
    for (LL i = 0; i < factors.size(); ++i) {
        for (LL j = i; j < factors.size(); ++j) { 
            LL f3 = k / (factors[i] * factors[j]);
            if (factors[i] * factors[j] * f3 == k && k % (factors[i] * factors[j]) == 0) { 
                // 变成三个小到大的数相乘
                if (factors[i] > a || factors[j] > b || f3 > c) {
                    continue;
                }
                ans = max(ans, (a - factors[i] + 1) * (b - factors[j] + 1) * (c - f3 + 1));
            }
        }
    }
    cout << ans << '\n';
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