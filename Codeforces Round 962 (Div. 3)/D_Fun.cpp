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

    int ans = 0;
    for (int a = 1; a <= min(n, x); a++) {
        for (int b = 1; a * b <= n && a + b <= x; b++) {
            ans += min((n - a * b) / (a + b), x - a - b);
        }
        // int l = 0, r = min(n, x), mid;
        // while (l < r) {
        //     mid = l + r + 1 >> 1;
        //     if (x - a - mid && n - a * mid >= a + mid) {
        //         l = mid;
        //     } else {
        //         r = mid - 1;
        //     }
        // }

        // if (l == 0) {
        //     continue;
        // }
        
        // for (int b = 1; b <= l; b++) {
        //     ans += min((n - a * b) / (a + b), x - a - b);
        // }
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