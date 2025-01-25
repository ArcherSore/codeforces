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
    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    for (int i =0 ; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int res = 0;
    for (auto [x, c] : cnt) {
        int pi = k - x;
        if (cnt.find(pi) != cnt.end()) {
            res += min(cnt[x], cnt[pi]);
        }
    }

    cout << res / 2 << '\n';
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