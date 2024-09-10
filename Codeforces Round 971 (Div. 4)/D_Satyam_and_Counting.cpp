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
    map<PII, int> point;
    map<int, int> x_cnt, y_cnt;
    map<int, vector<int>> x_to_y, y_to_x;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        point[{a, b}]++;
        x_cnt[a]++, y_cnt[b]++;
        x_to_y[a].push_back(b);
        y_to_x[b].push_back(a);
    }

    LL ans = 0;
    for (auto [x, cnt] : x_cnt) {
        if (cnt < 2) {
            continue;
        }
        for (auto y : x_to_y[x]) {
            ans += y_cnt[y] - 1;
        }
    }

    for (auto [p, cnt] : point) {
        if (point.find({p.first - 1, 1 - p.second}) != point.end() && point.find({p.first + 1, 1 - p.second}) != point.end()) {
            ans += 1LL * cnt * point[{p.first - 1, 1 - p.second}] * point[{p.first + 1, 1 - p.second}];
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