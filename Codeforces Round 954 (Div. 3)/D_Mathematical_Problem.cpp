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
    string s;
    cin >> s;

    int ans = 1e9;
    for (int i = 0; i < n - 1; i++) {
        vector<int> v;
        for (int j = 0; j < n; j++) {
            if (j == i) {
                int t = (s[j] - '0') * 10 + (s[j + 1] - '0');
                v.push_back(t);
                j++;
            } else {
                int t = s[j] - '0';
                v.push_back(t);
            }
        }
        sort(v.begin(), v.end(), greater());
        int tot = 0;
        for (auto x : v) {
            if (x > 1) {
                tot += x;
            } else if (x == 1) {
                if (tot == 0) {
                    tot += 1;
                }
            } else {
                tot *= x;
            }
        }
        ans = min(ans, tot);
    }
    if (n == 2) {
        ans = 10 * (s[0] - '0') + s[1] - '0';
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