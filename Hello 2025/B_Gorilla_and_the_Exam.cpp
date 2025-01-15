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
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    vector<int> v;
    for (auto [x, n] : cnt) {
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < cnt.size() - 1; i++) {
        if (sum + v[i] <= k) {
            sum += v[i];
        } else {
            cout << cnt.size() - i << '\n';
            return;
        }
    }
    cout << 1 << '\n';
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