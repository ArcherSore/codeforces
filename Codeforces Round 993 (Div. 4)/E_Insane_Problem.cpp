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

const int INF = 1e9;

LL fpow(LL a, LL x) {
    LL res = 1;
    while (x) {
        if (x & 1) {
            res = res * a;
        }
        a = a * a;
        x >>= 1;
    }
    return res;
}

void solve() {
    LL k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    LL res = 0;
    for (int i = 0; i < 40; i++) {
        LL t = fpow(k, i);
        if (t > INF) {
            break;
        }
        LL l = ceil(1.0 * l2 / t), r = r2 / t;
        l = max(l, l1), r = min(r, r1);
        res += max(0LL, r - l + 1);
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