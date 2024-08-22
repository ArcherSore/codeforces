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
    LL n, m;
    cin >> n >> m;
    vector<pair<LL, LL>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end());

    LL ans = 0;
    // choose two different kinds of flowers
    for (int i = 1; i < n; i++) {
        if (v[i].first != v[i - 1].first + 1) {
            continue;
        }

        LL tot = v[i].first * v[i].second + v[i - 1].first * v[i - 1].second;
        if (tot <= m) {
            ans = max(ans, tot);
        } else {
            LL cnt_fir = min(v[i - 1].second, m / v[i - 1].first);
            LL cnt_sec = (m - v[i - 1].first * cnt_fir) / v[i].first;

            LL cur = v[i - 1].first * cnt_fir + v[i].first * cnt_sec;
            ans = max(ans, min(m, cur + min(v[i].second - cnt_sec, cnt_fir)));
        }
    }
    // choose a kind of flowers
    for (int i = 0; i < n; i++) {
        if (v[i].first * v[i].second <= m) {
            ans = max(ans, v[i].first * v[i].second);
        } else {
            ans = max(ans, m / v[i].first * v[i].first);
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