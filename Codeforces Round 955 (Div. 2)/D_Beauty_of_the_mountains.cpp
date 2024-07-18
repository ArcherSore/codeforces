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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    
    vector<vector<LL>> sum(n + 1, vector<LL> (m + 1)); // the sum of '0'
    LL sum1 = 0, sum2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char caps;
            cin >> caps;
            if (caps == '0') {
                sum1 += a[i][j];
                sum[i][j] = 1 + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            } else {
                sum2 += a[i][j];
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
            }
        }
    }

    set<LL> v;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= m; j++) {
            LL num0 = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
            LL num1 = k * k - num0;
            if (abs(num0 - num1)) {
                v.insert(abs(num0 - num1));
            }
        }
    }

    LL divs = abs(sum1 - sum2);
    if (v.empty()) {
        if (divs == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    LL tmp = *(v.begin());
    for (auto x : v) {
        tmp = gcd(tmp, x);
    }
    
    if (divs % tmp == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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