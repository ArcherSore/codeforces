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

bool check(vector<int> &v, int n, int k, int x) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (v[i] >= x) {
            b[i] = 1;
        } else {
            b[i] = -1;
        }
    }

    vector<int> f(n);
    f[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (i % k == 0) {
            f[i] = max(f[i - k], b[i]);
        } else {
            f[i] = f[i - 1] + b[i];
            if (i > k) {
                f[i] = max(f[i], f[i - k]);
            }
        }
    }

    return f[n - 1] > 0;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int l = 1, r = 1e9, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(v, n, k, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << '\n';
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