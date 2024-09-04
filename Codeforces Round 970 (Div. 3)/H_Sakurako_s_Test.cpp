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

bool check(vector<int> &sum, int n, int x, int k) {
    int tot = 0;
    for (int i = 0; i <= n; i += x) {
        // [i, i + k]
        tot += sum[min(i + k, n)] - sum[max(i - 1, 0)]; 
    }
    return tot >= n / 2 + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<int> cnt(n + 1), sum(n + 1);
    for (int i = 0; i < n; i++) {
        cnt[v[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + cnt[i];
    }

    vector<int> ans(n + 1);
    for (int x = 1; x <= n; x++) {
        int l = 0, r = x - 1, mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (check(sum, n, x, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        ans[x] = l;
    }

    while (q--) {
        int a;
        cin >> a;
        cout << ans[a] << ' ';
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