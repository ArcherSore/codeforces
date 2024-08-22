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
    vector<int> v;
    v.push_back(n);
    for (int i = n - 1; i > 0; i--) {
        v.push_back(i);
        v.push_back(i);
    }

    int ans = 0;
    for (auto x : v) {
        if (k > 0) {
            ans++;
            k -= x;
        } else {
            break;
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