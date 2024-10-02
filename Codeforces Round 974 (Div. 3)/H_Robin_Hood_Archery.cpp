// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <array>
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

const int N = 1e6 + 5;

int f[N + 5];

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]] = 0; // 初始化
    }

    int batch = sqrt(n) + 1;
    vector<array<int, 3>> query(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> query[i][0] >> query[i][1];
        query[i][2] = i;
    }
    sort(query.begin(), query.end(), [&](array<int, 3> &a, array<int, 3> &b) {
        return make_pair(a[0] / batch, a[1] / batch) < make_pair(b[0] / batch, b[1] / batch);
    });

    int cnt = 0;
    auto add = [&](int l, int r) -> void {
        for (int i = l; i <= r; i++) {
            f[a[i]] = 1 - f[a[i]];
            cnt += f[a[i]] == 0 ? -1 : 1;
        }
    };
    auto remove = [&](int l, int r) -> void {
        for (int i = l; i <= r; i++) {
            f[a[i]] = 1 - f[a[i]];
            cnt += f[a[i]] == 0 ? -1 : 1;
        }
    };

    map<PII, string> ans;
    PII last = {-1, -1};
    for (auto arr : query) {
        int l = arr[0], r = arr[1];
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
        last = make_pair(l, r);

        ans[{l, r}] = cnt ? "NO\n" : "YES\n";
    }

    sort(query.begin(), query.end(), [&](array<int, 3> &a, array<int, 3> &b) {
        return a[2] < b[2];
    });

    for (auto arr : query) {
        auto x = make_pair(arr[0], arr[1]);
        cout << ans[x];
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