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
    int xc, yc, k;
    cin >> xc >> yc >> k;

    if (k % 2) {
        cout << xc << " " << yc << '\n';
        k -= 1;
    }

    for (int x = xc - k / 2, y = yc - k / 2; x <= xc + k / 2; x++, y++) {
        if (x == xc) {
            continue;
        }
        cout << x << ' ' << y << '\n';
    }
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