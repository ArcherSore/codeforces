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
    vector<LL> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    LL ans = 0;
    vector<int> cnt(n);
    for (int i = 1; i < n; i++) {
        if (v[i] == 1 && v[i - 1] > 1) {
            cout << -1 << '\n';
            return;
        }

        if (1.0 * cnt[i - 1] + log2(log2(v[i - 1])) <= 1.0 * cnt[i] + log2(log2(v[i]))) {
            continue;
        }
        
        cnt[i] = cnt[i - 1] + ceil(log2(log(v[i - 1]) / log(v[i])));
        ans += cnt[i];
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