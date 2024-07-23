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

struct Weapon {
    LL dif, a;
    bool operator<(const Weapon &other) const {
        if (dif != other.dif) {
            return dif > other.dif;
        }
        return a < other.a;
    }
};

bool cmp(const Weapon &a, const Weapon &b) {
    return a.a < b.a;
}

void solve() {
    // input
    int n, m;
    cin >> n >> m;
    vector<LL> a(n), b(n), c(m);
    LL A = 0; // max{a[i]}
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        A = max(A, a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }

    vector<Weapon> v(n);
    for (int i = 0; i < n; i++) {
        v[i].dif = a[i] - b[i];
        v[i].a = a[i];
    }
    sort(v.begin(), v.end(), cmp); // sort v based on a
    // for (auto [dif, a] : v) {
    //     cout << a << " " << dif << '\n';
    // }

    vector<LL> dp(A + 1);
    priority_queue<Weapon> st;
    int p = 0;
    for (int i = 1; i <= A; i++) {
        while (p < n && v[p].a <= i) {
            st.push(v[p]);
            p += 1;
        }
        if (st.empty()) {
            continue;
        }

        auto [dif, a] = st.top();
        LL times = (i - a) / dif + 1;
        dp[i] = dp[i - times * dif] + 2 * times;
    }
    // for (auto x : dp) {
    //     cout << x << " ";
    // }
    // cout << '\n';

    LL ans = 0;
    for (int i = 0; i < m; i++) {
        if (c[i] > A) {
            auto [dif, a] = st.top();
            LL times = (c[i] - a) / dif + 1;
            ans += dp[c[i] - times * dif] + 2 * times;
        } else {
            ans += dp[c[i]];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}