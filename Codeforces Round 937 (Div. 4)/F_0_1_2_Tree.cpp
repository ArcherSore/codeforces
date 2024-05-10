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
    int a, b, c;
    cin >> a >> b >> c;
    int k = log2(a + 1), extra = a - (1 << k) + 1, rest = (1 << k) - extra;
    if (c != rest + extra * 2) {
        cout << -1 << '\n';
        return;
    }
    rest %= (1 << k);
    // cout << k << " " << extra << " " << rest << '\n';
    if (rest) {
        k += 1;
    }
    if (b < rest) {
        cout << k << '\n';
    } else {
        b -= rest;
        if (b % c == 0) {
            cout << k + b / c << '\n';
        } else {
            cout << k + b / c + 1 << '\n';
        }
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