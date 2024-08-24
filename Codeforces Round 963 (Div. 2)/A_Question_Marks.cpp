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
    map<char, int> mp;
    for (auto c : s) {
        if (c == '?') {
            continue;
        }
        mp[c]++;
    }

    int cnt = 0;
    for (auto [c, x] : mp) {
        if (x >= n) {
            cnt += n;
        } else {
            cnt += x;
        }
    }

    cout << cnt << '\n';
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