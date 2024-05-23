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

int a, b, n, m;

int cal(set<PII> &up, set<PII> &down, set<PII> &left, set<PII> &right, int &row_f, int &col_f, int &row_b, int &col_b) {
    char opt;
    int k, tot = 0;
    cin >> opt >> k;
    if (opt == 'U') {
        while (!up.empty() && (*up.begin()).first - row_f <= k) {
            auto [x, y] = *up.begin();
            down.erase({-x, y});
            left.erase({y, x});
            right.erase({-y, x});
            tot++;
            up.erase(up.begin());
        }
        row_f += k;
    }
    if (opt == 'D') {
        while (!down.empty() && -(*down.begin()).first + row_b >= a - k + 1) {
            auto [x, y] = *down.begin();
            up.erase({-x, y});
            left.erase({y, -x});
            right.erase({-y, -x});
            tot++;
            down.erase(down.begin());
        }
        row_b += k;
    }
    if (opt == 'L') {
        while (!left.empty() && (*left.begin()).first - col_f <= k) {
            auto [y, x] = *left.begin();
            up.erase({x, y});
            down.erase({-x, y});
            right.erase({-y, x});
            tot++;
            left.erase(left.begin());
        }
        col_f += k;
    }
    if (opt == 'R') {
        while (!right.empty() && -(*right.begin()).first + col_b >= b - k + 1) {
            auto [y, x] = *right.begin();
            up.erase({x, -y});
            down.erase({-x, -y});
            left.erase({-y, x});
            tot++;
            right.erase(right.begin());
        }
        col_b += k;
    }
    return tot;
}

void solve() {
    cin >> a >> b >> n >> m;
    set<PII> up, down, left, right;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        up.insert({x, y});
        down.insert({-x, y});
        left.insert({y, x});
        right.insert({-y, x});
    }

    int row_f = 0, col_f = 0; // 行 列从头部减少了多少
    int row_b = 0, col_b = 0; // 行 列从末尾减少了多少
    int bob = 0, alice = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2) {
            bob += cal(up, down, left, right, row_f, col_f, row_b, col_b);
        } else {
            alice += cal(up, down, left, right, row_f, col_f, row_b, col_b);
        }
    }
    
    cout << alice << " " << bob << '\n';
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