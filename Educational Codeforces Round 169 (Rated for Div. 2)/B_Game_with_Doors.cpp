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
    int l, r, L, R;
    cin >> l >> r >> L >> R;
    if (r < L || l > R) {
        cout << 1 << '\n';
    } else {
        int overlap = min(r, R) - max(l, L) + 1;
        if (l == L && r == R) {
            overlap -= 1;
        } else if (l == L || r == R) {

        } else {
            overlap += 1;
        }
        cout << overlap << '\n';
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