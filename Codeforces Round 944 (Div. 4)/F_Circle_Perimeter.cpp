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

LL bs1(LL st, LL y) {
    LL l = 0, r = y, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (st <= mid * mid) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

LL bs2(LL st, LL y) {
    LL l = 0, r = y, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (st > mid * mid) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    LL r;
    cin >> r;
    LL res = 0;
    for (LL x = 0; x <= r; x++) {
        LL yl = bs1(r * r - x * x, r);
        LL yr = bs2(r * r - x * x + 2 * r + 1LL, r);
        res += max(yr - yl + 1, 0LL);
    }
    cout << 4 * (res - 1) << '\n';
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