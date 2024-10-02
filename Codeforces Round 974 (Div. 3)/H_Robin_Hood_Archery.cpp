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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int block = sqrt(n - 1) + 1, m = round(sqrt(n)); // block块, 每块m大小
    vector<PII> ori_query(q);
    vector<vector<PII>> query(block);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        ori_query[i] = {l, r};
        query[(l - 1) / m].push_back({l, r});
    }
    for (auto &v : query) {
        sort(v.begin(), v.end(), [](const PII a, const PII b) {
            return a.second < b.second;
        });
    }
    int cnt = 0;
    map<int, int> mp;
    auto add = [&](int l, int r) -> void {
        for (int i = l; i <= r; i++) {            
            auto freq = mp[a[i]]++;
            if (freq > 1) {
                if (freq % 2 == 0) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
    };
    auto remove = [&](int l, int r) -> void {
        int odd = 0;
        for (int i = l; i <= r; i++) {
            auto freq = mp[a[i]]--;
            if (mp[a[i]] == 0) {
                mp.erase(a[i]);
            }
            if (freq >= 1) {
                if (freq % 2 == 0) {
                    cnt++;
                } else {
                    cnt--;
                }
            }
        }
    };

    map<PII, string> ans;
    PII last = {-1, -1};
    for (auto v : query) {
        for (auto x : v) {
            auto [l, r] = x;
            auto [ll, rr] = last;
            if (ll == -1) {
                add(l, r);
            } else {
                if (l < ll) {
                    add(l, ll - 1);
                } else {
                    remove(ll, l - 1);
                }
                if (r < rr) {
                    remove(r + 1, rr);
                } else {
                    add(rr + 1, r);
                }
            }
            last = x;
            
            if (cnt == mp.size()) {
                ans[x] = "YES\n";
            } else {
                ans[x] = "NO\n";
            }
        }
    }

    for (auto q : ori_query) {
        cout << ans[q];
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