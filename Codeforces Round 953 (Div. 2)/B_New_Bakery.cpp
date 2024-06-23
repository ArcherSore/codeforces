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
    LL n, a, b;
    cin >> n >> a >> b;

    LL l = 0, r = min(n, b), mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (b - mid + 1 >= a) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << (2 * b - l + 1) * l / 2 + a * (n - l) << '\n';
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