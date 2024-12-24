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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    stack<PII> segs;
    bool bot = false, top = false;
    segs.push({m, m});
    for (int i = 0; i < q; i++) {
        set<PII> s;
        // 更新区间
        while (!segs.empty()) {
            auto [l, r] = segs.top();
            segs.pop();
            if (a[i] < l) {
                if (l - 1 == 1) {
                    bot = true;
                }
                s.insert({max(l - 1, 1), r});
            } else if (a[i] > r) {
                if (r + 1 == n) {
                    top = true;
                }
                s.insert({l, min(r + 1, n)});
            } else {
                if (!bot) {
                    s.insert({1, 1});
                    bot = true;
                }
                if (!top) {
                    s.insert({n, n});
                    top = true;
                }
                if (i != 0) {
                    s.insert({l, r});
                }
            }
        }
        // 合并相交区间
        int ans = 0;
        for (auto [l, r] : s) {
            if (segs.empty()) {
                segs.push({l, r});
                ans += r - l + 1;
            } else {
                auto [tl, tr] = segs.top();
                if (l == tr) {
                    segs.pop();
                    segs.push({tl, r});
                    ans += r - l;
                } else {
                    segs.push({l, r});
                    ans += r - l + 1;
                }
            }
        }
        cout << ans << ' ';
    }
    cout << '\n';
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