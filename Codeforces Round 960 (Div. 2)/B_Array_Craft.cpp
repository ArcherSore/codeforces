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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(n + 1);
    for (int i = y; i <= x; i++) {
        ans[i] = 1;
    }
    for (int i = x + 1; i <= n; i++) {
        if ((i - x) % 2) {
            ans[i] = -1;
        } else {
            ans[i] = 1;
        }
    }
    for (int i = y - 1; i >= 1; i--) {
        if ((y - i) % 2) {
            ans[i] = -1;
        } else {
            ans[i] = 1;
        }
    }


    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
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