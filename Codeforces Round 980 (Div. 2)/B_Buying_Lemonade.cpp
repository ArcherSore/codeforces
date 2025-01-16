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
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    } 
    sort(v.begin(), v.end());
    queue<int> q;
    for (auto x : v) {
        q.push(x);
    }

    int t = 0;
    int ans = 0;
    while (!q.empty()) {
        if (1LL * q.size() * (q.front() - t) >= 1LL * k) {
            ans += k;
            break;
        }
        ans += q.size() * (q.front() - t);
        k -= q.size() * (q.front() - t);
        t = q.front();
        while (!q.empty() && q.front() == t) {
            q.pop();
            ans += 1;
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