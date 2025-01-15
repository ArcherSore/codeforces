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
    vector<int> l(n), r(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        if (l[i] == r[i]) {
            mp[l[i]]++;
        }
    }
    vector<int> v;
    for (auto [x, n] : mp) {
        v.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        if (l[i] == r[i]) {
            if (mp[l[i]] == 1) {
                cout << 1;
            } else {
                cout << 0;
            }
        } else {
            auto pl = lower_bound(v.begin(), v.end(), l[i]);
            auto pr = upper_bound(v.begin(), v.end(), r[i]);
            if (pr - pl <= r[i] - l[i]) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
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