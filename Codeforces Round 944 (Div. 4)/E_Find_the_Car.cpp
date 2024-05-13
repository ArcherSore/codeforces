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

LL bs(vector<LL> &a, LL n, LL x) {
    LL l = 0, r = n, mid;
    while (l < r) {
        mid = l + r + 1 >> 1;
        if (a[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}

void solve() {
    LL n, k, q;
    cin >> n >> k >> q;
    vector<LL> a(k + 1), t(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> t[i];
    }

    while (q--) {
        LL x;
        cin >> x;
        LL p = bs(a, k, x);
        // cout << p << '\n';
        if (p == k) {
            cout << t[k] << ' ';
            continue;
        }
        // cout << "v = " << (a[p + 1] - a[p]) / (t[p + 1] - t[p]) << " t = " << t[p] << '\n';
        // cout << x - a[p] << '\n';
        LL res = t[p] + (x - a[p]) * (t[p + 1] - t[p]) / (a[p + 1] - a[p]);
        cout << res << ' ';
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