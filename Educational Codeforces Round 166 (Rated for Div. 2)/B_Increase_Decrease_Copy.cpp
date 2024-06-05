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
    int n;
    cin >> n;
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    LL res = 0;
    for (int i = 0; i <= n; i++) {
        cin >> b[i];
    }
    int dif = 1e9;
    for (int i = 0; i < n; i++) {
        res += 1LL * abs(a[i] - b[i]);
        if (min(a[i], b[i]) <= b[n] && b[n] <= max(a[i], b[i])) {
            dif = 0;
        } else {
            dif = min(dif, min(abs(b[n] - a[i]), abs(b[n] - b[i])));
        }
    }
    res += 1LL + 1LL * dif;
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