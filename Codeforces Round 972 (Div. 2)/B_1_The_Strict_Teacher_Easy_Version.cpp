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

PII find(vector<int> &b, int a, int n) {
    int p = lower_bound(b.begin(), b.end(), a) - b.begin();
    if (p == 0) {
        return {-1, b[p]};
    } else if (p == b.size()) {
        return {b[p - 1], n + 1};
    } else {
        return {b[p - 1], b[p]};
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    while (q--) {
        int a;
        cin >> a;
        PII pos = find(b, a, n);
        // cout << pos.first << ' ' << pos.second << '\n';
        if (pos.first == -1) {
            cout << pos.second - 1 << '\n';
        } else if (pos.second == n + 1) {
            cout << n - pos.first << '\n';
        } else {
            cout << (pos.second - pos.first) / 2 << '\n';
        }
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