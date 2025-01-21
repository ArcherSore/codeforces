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
    vector<int> to(n);
    vector<vector<int>> from(n);
    for (int i = 0; i < n; i++) {
        cin >> to[i];
        to[i]--;
        from[to[i]].push_back(i);
    }

    vector<int> d(n, -1);
    vector<int> cyc(n);
    for (int i = 0; i < n; i++) {
        if (d[i] != -1) {
            continue;
        }
        int cur = i;
        vector<int> s;
        while (d[cur] == -1) {
            s.push_back(cur);
            d[cur] = 0;
            cur = to[cur];
        }
        auto it = find(s.begin(), s.end(), cur);
        for (int k = it - s.begin(); k < s.size(); k++) {
            cyc[s[k]] = 1;
        }
    }

    int ans = 0, cnt = 0;
    auto dfs = [&](auto &self, int u) -> void {
        cnt += 1;
        for (auto v : from[u]) {
            self(self, v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!cyc[i] && cyc[to[i]]) {
            cnt = 0;
            dfs(dfs, i);
            ans = max(ans, cnt);
        }
    }
    cout << ans + 2 << '\n';
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