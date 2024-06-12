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

bool check(vector<LL> &a, vector<LL> &c, LL h, LL mid) {
    LL tot = 0;
    for (int i = 0; i < a.size(); i++) {
        tot += ((mid - 1) / c[i] + 1) * a[i];
        if (tot >= h) {
            return true;
        }
    }
    return false;
}

void solve() {
    LL h, n;
    cin >> h >> n;
    vector<LL> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    LL l = 1, r = 5e10, mid;
    while (l < r) {
        mid = l + r >> 1;
        if (check(a, c, h, mid)) {
            r = mid;
        } else {
            l = mid + 1;
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