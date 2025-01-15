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
    LL ans = 0;
    if (n & 1) {
        LL t = (1 + n) / 2;
        while (n >= k) {
            if (n & 1) {
                ans += t;
            }
            n /= 2;
            t *= 2;
        }
    } else {
        LL t = (1 + n);
        n /= 2;
        while (n >= k) {
            if (n & 1) {
                ans += t;
            }
            n /= 2;
            t *= 2;
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