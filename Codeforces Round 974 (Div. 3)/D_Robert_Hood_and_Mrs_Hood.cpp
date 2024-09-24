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
    int n, k, m;
    cin >> n >> k >> m;
    vector<PII> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());

    priority_queue<PII, vector<PII>, greater<>> q;
    int p = 0;
    for (; p < m; p++) {
        int l = v[p].first, r = v[p].second;
        if (l <= k) {
            q.push({r, p});
        } else {
            break;
        }
    }

    int maxx = q.size(), minn = q.size();
    int ans1 = 1, ans2 = 1;

    for (int i = 2; i <= n - k + 1; i++) {
        while (!q.empty() && v[q.top().second].second < i) {
            q.pop();
        }
        while (v[p].first <= i + k - 1 && p < m) {
            q.push({v[p].second, p});
            p++;
        }

        if (q.size() > maxx) {
            maxx = q.size();
            ans1 = i;
        }
        if (q.size() < minn) {
            minn = q.size();
            ans2 = i;
        }
    }

    cout << ans1 << ' ' << ans2 << '\n';
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