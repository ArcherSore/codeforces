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

    if (n == 1) {
        cout << ((k <= v[0]) ? k - 1 : k) << '\n';
        return;
    }

    int std = v[0];
    for (int i = 1; i < n; i++) {
        std = gcd(std, v[i]);
    }

    if (std == 1) {
        cout << n + k - 1 << '\n';
    } else {
        // cout << "gcd = " << std << '\n';
        if (1LL * (n - 1) * (std - 1) >= k) {
            int cnt = k / (std - 1);
            if (k % (std - 1) == 0) {
                cout << cnt * std - 1 << '\n';
            } else {
                cout << cnt * std + k - cnt * (std - 1) << '\n';
            }
        } else {
            cout << n + k - 1 << '\n';
        }
    }
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