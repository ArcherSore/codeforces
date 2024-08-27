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

bool check(vector<pair<LL, int>> &v, LL n, LL k, LL x) {
    vector<int> b(n);
    for (int i = n - 1; i >= 0; i--) {
        if (v[i].first >= x) {
            b[i] = 1;
            continue;
        }

        if (v[i].first + k >= x) {
            if (v[i].second == 1) {
                b[i] = 1;
                k -= x - v[i].first;
            } else {
                b[i] = -1;
            }
        } else {
            b[i] = -1;
        }
    }

    int tot = 0;
    for (int i = 0; i < n; i++) {
        tot += b[i];
    }

    return tot > 0;
}

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<pair<LL, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    // if (v.back().second == 1) {
    //     cout << v.back().first + k + v[(n - 2) / 2].first << '\n';
    //     return;
    // }

    LL ans1 = -1, ans2 = -1;
    LL l = v[0].first, r = v[n - 2].first + k, mid;
    while (l < r) {
        mid = (l + r + 1) / 2;
        if (check(v, n - 1, k, mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    ans1 = l + v[n - 1].first;

    for (int i = n - 1; i >= 0; i--) {
        if (v[i].second == 1) {
            ans2 = v[i].first + k;
            v.erase(v.begin() + i);
            break;
        }
    }
    if (ans2 != -1) {
        n -= 1;
        ans2 += v[(n - 1) / 2].first;
    }
    
    cout << max(ans1, ans2) << '\n';
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