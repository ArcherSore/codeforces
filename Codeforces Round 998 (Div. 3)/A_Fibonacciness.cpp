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
    vector<int> a(5);
    cin >> a[0] >> a[1] >> a[3] >> a[4];

    int res = 0, tot = 0;
    a[2] = a[0] + a[1];
    for (int i = 0; i < 3; i++) {
        if (a[i + 2] == a[i + 1] + a[i]) {
            tot += 1;
        }
    }
    res = max(res, tot);

    a[2] = a[3] - a[1];
    tot = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i + 2] == a[i + 1] + a[i]) {
            tot += 1;
        }
    }
    res = max(res, tot);

    a[2] = a[4] - a[3];
    tot = 0;
    for (int i = 0; i < 3; i++) {
        if (a[i + 2] == a[i + 1] + a[i]) {
            tot += 1;
        }
    }
    res = max(res, tot);

    cout << res << '\n';
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