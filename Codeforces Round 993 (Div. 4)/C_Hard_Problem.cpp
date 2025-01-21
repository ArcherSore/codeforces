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
    int m, a, b, c;
    cin >> m >> a >> b >> c;
    int extra = 0, seated = 0;

    if (a <= m) {
        seated += a;
        extra += m - a;
    } else {
        seated += m;
    }

    if (b <= m) {
        seated += b;
        extra += m - b;
    } else {
        seated += m;
    }

    cout << seated + min(extra, c) << '\n';
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