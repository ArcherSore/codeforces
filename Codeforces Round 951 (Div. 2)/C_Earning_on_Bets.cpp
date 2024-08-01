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
    vector<LL> v(n);
    LL res, maxv = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        maxv = max(maxv, v[i]);
        if (i) {
            res = lcm(res, v[i]);
        } else {
            res = v[i];
        }
    }

    vector<LL> ans;
    LL tot = 0;
    for (int i = 0; i < n; i++) {
        ans.push_back(res / v[i]);
        // cout << res / v[i] << " ";
        tot += ans.back();
    }
    if (tot < res) {
        for (auto c : ans) {
            cout << c << " ";
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
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