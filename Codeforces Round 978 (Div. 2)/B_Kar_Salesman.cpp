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
    int n, x;
    cin >> n >> x;
    LL tot = 0;
    int mx = 0;
    for (int i = 0, xx; i < n; i++) {
        cin >> xx;
        mx = max(xx, mx);
        tot += xx;
    }
    cout << max(1LL * mx, (LL)ceil(1.0 * tot / x)) << endl;;
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