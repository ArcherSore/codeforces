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

const int MOD = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<LL> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (s[i - 1] == '0' ? -1 : 1);
    }

    LL ans = 0;
    map<int, LL> mp;
    mp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (mp.find(sum[i]) != mp.end()) {
            // TODO
            ans = (ans + (n - i + 1) * mp[sum[i]]) % MOD;
            mp[sum[i]] += i + 1;
        } else {
            mp[sum[i]] = i + 1;
        }
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