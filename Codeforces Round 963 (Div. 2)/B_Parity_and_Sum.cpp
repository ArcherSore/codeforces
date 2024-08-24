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
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<LL> odd, even;
    for (auto x : v) {
        if (x % 2) {
            odd.push_back(x);
        } else {
            even.push_back(x);
        }
    }

    if (even.empty() || odd.empty()) {
        cout << 0 << '\n';
        return;
    }

    int ans = 0;
    LL maxx = odd.back();
    for (int i = 0; i < even.size(); i++) {
        if (even[i] <= maxx) {
            maxx += even[i];
            ans++;
        } else {
            if (i < even.size() - 1) {
                ans++;
            }
            maxx += 2 * even.back();
            even.pop_back();
            ans += 2;
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