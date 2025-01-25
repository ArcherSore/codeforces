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
    int n, l, r;
    cin >> n >> l >> r;
    l--, r--;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> a(v.begin(), v.begin() + l);
    vector<int> b(v.begin() + l, v.begin() + r + 1);
    vector<int> c(v.begin() + r + 1, v.end());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int> ());
    sort(c.begin(), c.end());

    LL sum = 0, res = 1e18;
    int p = 0;
    while (p < a.size() && p < b.size() && a[p] < b[p]) {
        sum += a[p];
        p++;
    }
    for (int i = p; i < b.size(); i++) {
        sum += b[i];
    }
    res = min(res, sum);

    p = 0, sum = 0;
    while (p < c.size() && p < b.size() && c[p] < b[p]) {
        sum += c[p];
        p++;
    }
    for (int i = p; i < b.size(); i++) {
        sum += b[i];
    }
    res = min(res, sum);

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