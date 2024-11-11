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

bool check(int x, int y) {
    int ans1, ans2;
    cout << "? " << x << ' ' << y << endl;
    cin >> ans1;
    cout << "? " << y << ' ' << x << endl;
    cin >> ans2;

    return ans1 == ans2;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2 * 2; i += 2) {
        if (!check(i, i + 1)) {
            // one of two people is imposor
            if (i > 1) {
                if (!check(i - 1, i)) {
                    cout << "! " << i << endl;
                } else {
                    cout << "! " << i + 1 << endl;
                }
            } else {
                if (!check(i + 1, i + 2)) {
                    cout << "! " << i + 1 << endl;
                } else {
                    cout << "! " << i << endl;
                }
            }
            return;
        }
    }
    cout << "! " << n << endl;
    return;
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