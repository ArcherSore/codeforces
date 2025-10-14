#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    LL x, y;
    cin >> x >> y;

    for (LL i = 0; i <= 1e6; i++) {
        LL tc = y - 1000 * (x - i); // C
        LL tb = 2500 * (x - i) - y; // B

        if (tb < 0 || tc < 0) {
            continue;
        }

        if (tb % 1500 == 0 && tc % 1500 == 0) {
            cout << i << ' ' << tb / 1500 << ' ' << tc / 1500;
            return;
        }
    }

    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}