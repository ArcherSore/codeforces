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
    int x, y, k;
    cin >> x >> y >> k;
    
    int cnt1 = x == 0 ? 0 : (x - 1) / k + 1, cnt2 = y == 0 ? 0 : (y - 1) / k + 1;
    // cout << cnt1 << ' ' << cnt2 << '\n';
    cout << max(cnt1, cnt2) * 2 - (cnt1 > cnt2) << '\n';
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