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
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int ones = 0, minus_ones = 0, as = 0, bs = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == 1) {
                ones += a[i];
            } else {
                minus_ones -= a[i];
            }
        } else {
            if (a[i] > b[i]) {
                as += a[i];
            } else {
                bs += b[i];
            }
        }
    }

    int dif = abs(as - bs), ans;
    if (ones + minus_ones >= dif) {
        if (minus_ones <= dif) {
            dif -= minus_ones;
            ones -= dif;
            ans = max(as, bs) - minus_ones + ones / 2;
        } else {
            minus_ones -= dif;
            if (ones >= minus_ones) {
                ones -= minus_ones;
                ans = min(as, bs) + ones / 2;
            } else {
                minus_ones -= ones;
                ans = min(as, bs) - (minus_ones + 1) / 2;
            }
        }
    } else {
        ans = min(as, bs) + ones;
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