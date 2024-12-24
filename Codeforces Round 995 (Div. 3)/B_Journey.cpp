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
    LL n, a, b, c;
    cin >> n >> a >> b >> c;
    LL t = 0;
    if (a + b + c <= n) {
        t += n / (a + b + c);
        n -= t * (a + b + c);
        t *= 3;
    }
    if (n == 0) {
        cout << t << '\n';
        return;
    }
    if (a >= n) {
        cout << t + 1 << '\n';
        return;
    }
    if (a + b >= n) {
        cout << t + 2 << '\n';
        return;
    }
    cout << t + 3 << '\n';
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