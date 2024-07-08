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

LL minimize(vector<int> &v) {
    int n = v.size();
    vector<LL> sum1(n), sum2(n);
    for (int i = 0; i < v.size(); i += 2) {
        if (i == 0) {
            sum1[i] = v[i];
        } else {
            sum1[i] = sum1[i - 2] + v[i];
        }
    }
    for (int i = 1; i < v.size(); i += 2) {
        if (i == 1) {
            sum2[i] = v[i];
        } else {
            sum2[i] = sum2[i - 2] + v[i];
        }
    }

    LL ans = 1e18;
    for (int i = 1; i < v.size() - 1; i++) {
        ans = min(ans, sum1[i / 2 * 2] + sum2[n - 1] - sum2[i % 2 ? i : i - 1]);
    }
    ans = min(ans, min(sum1[n - 2], sum2[n - 1]));
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x % k].push_back(x);
    }

    // check if more than 2 map whose size is odd
    int cnt = 0;
    for (auto [id, v] : mp) {
        if (v.size() % 2) {
            cnt++;
        }
        if (cnt > 1) {
            cout << -1 << '\n';
            return;
        }
    }

    LL ans = 0;
    for (auto [id, v] : mp) {
        sort(v.begin(), v.end());
        if (v.size() % 2) {
            vector<int> div;
            for (int i = 1; i < v.size(); i++) {
                div.push_back((v[i] - v[i - 1]) / k);
            }
            if (!div.empty()) {
                ans += minimize(div);
            }
        } else {
            for (int i = 0; i < v.size(); i += 2) {
                ans += 1LL * (v[i + 1] - v[i]) / k;
            }
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