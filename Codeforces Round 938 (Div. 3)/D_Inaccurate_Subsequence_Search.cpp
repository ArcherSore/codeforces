#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

const int MAXN = 1e6 + 10;

void solve() {
    LL n, m, k;
    cin >> n >> m >> k;
    vector<LL> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    map<LL, int> cnt1, cnt2;
    for (int i = 0; i < m; i++) {
        LL x;
        cin >> x;
        cnt1[x]++;
    }

    LL cnt = 0, res = 0;
    for (int i = 0; i < m; i++) {
        cnt2[b[i]]++;

        if (cnt2[b[i]] <= cnt1[b[i]]) {
            cnt++;
        }
    }
    if (cnt >= k) {
        res++;
    }

    for (int i = m; i < n; i++) {
        if (cnt2[b[i - m]] <= cnt1[b[i - m]]) {
            cnt -= 1;
        }
        cnt2[b[i - m]]--;

        cnt2[b[i]]++;
        if (cnt2[b[i]] <= cnt1[b[i]]) {
            cnt += 1;
        }
        
        if (cnt >= k) {
            res++;
        }
    }

    cout << res << '\n';
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