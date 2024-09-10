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

void solve() {
    LL n, k;
    cin >> n >> k;

    LL l = 1, r = n, mid;
    LL sum = (2 * k + n - 1) * n / 2;

    LL div;
    while (l < r) {
        mid = (l + r) / 2;
        LL tmp = (2 * k + mid - 1) * mid / 2;
        if (tmp >= sum - tmp) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    div = (2 * k + l - 1) * l - sum;
    // cout << div << ' ';

    l = 1, r = n;
    while (l < r) {
        mid = (l + r + 1) / 2;
        LL tmp = (2 * k + mid - 1) * mid / 2;
        if (tmp <= sum - tmp) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    div = min(div, sum - (2 * k + l - 1) * l);

    cout << div << '\n';
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