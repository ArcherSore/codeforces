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
    int n, x;
    cin >> n >> x;
    map<int, int> mp;
    int ans = 0, flag = 0;
    for (int i = 0, v; i < n; i++) {
        cin >> v;
        if (x % v == 0) {
            flag = 1;
            if (mp.find(x / v) != mp.end()) {
                ans += 1;
                mp.clear();
            }
            vector<int> tmp;
            for (auto [c, cnt] : mp) {
                if (1LL * c * v <= 1LL * x && x % (c * v) == 0) {
                    tmp.push_back(c * v);
                }
            }
            for (auto c : tmp) {
                mp[c] += 1;
            }
            mp[v] += 1;
        }
    }
    if (!mp.empty() || !flag) {
        ans += 1;
    }
    cout << ans << '\n';
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