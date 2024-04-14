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
    int n, m;
    cin >> n >> m;
    if (n == 1 || m == 1) {
        if (n == 1) {
            cout << m / 2 + 1 << '\n';
        } else {
            cout << n / 2 + 1 << '\n';
        }
    } else {
        if (abs(m - n) % 2 == 0) 
            cout << min(n, m) + abs(m - n) / 2 << '\n';
        else 
            cout << min(n, m) + abs(m - n) / 2 + 1 << '\n';
    }
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