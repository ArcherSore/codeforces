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

LL ceilDiv(LL x, LL y) {
    return (x + y - 1) / y;
}

void solve() {
    LL l, r, G;
    cin >> l >> r >> G;

    if (G > r) {
        cout << "-1 -1\n";
        return;
    }

    LL L = ceilDiv(l, G);
    LL R = r / G;

    if (R - L < 1) {
        if (R == L && R == 1) {
            cout << G << ' ' << G << '\n';
        } else {
            cout << "-1 -1\n";
        }
        return;
    }

    const LL max_check = 500;

    if (std::gcd(L, R) == 1) {
        cout << G * L << " " << G * R << "\n";
        return;
    }

    for (LL s = 0; s <= 2 * max_check; s++) {
        if (s > (R - L)) break;

        for (LL i = 0; i <= s; i++) {
            LL j = s - i;
            LL x_ = L + i;
            LL y_ = R - j;
            if (x_ <= y_) {
                if (gcd(x_, y_) == 1) {
                    cout << x_ * G << " " << y_ * G << "\n";
                    return;
                }
            }
        }
    }

    cout << "-1 -1\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}