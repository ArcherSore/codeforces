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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m), q(k);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < k; j++) {
        cin >> q[j];
    }

    if (n == k) {
        while (m--) {
            cout << 1;
        }
        cout << '\n';
    } else if (n > k + 1) {
        while (m--) {
            cout << 0;
        }
        cout << '\n';
    } else {
        vector<int> vis(n + 1);
        for (int x : q) {
            vis[x] = 1;
        }
        int miss;
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                miss = i;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (a[i] == miss) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << '\n';
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