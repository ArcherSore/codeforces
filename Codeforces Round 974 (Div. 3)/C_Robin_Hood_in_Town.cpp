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

bool check(vector<LL> &v, LL sum, LL x, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (2 * n * v[i] < sum + x) {
            cnt++;
        }
    }
    return 2 * cnt > n;
}

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);

    LL sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());

    if (n <= 2) {
        cout << -1 << '\n';
        return;
    }

    LL l = 0, r = 1e18, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(v, sum, mid, n)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    if (l < 0) {
        cout << -1 << '\n';
    } else {
        cout << l << '\n';
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