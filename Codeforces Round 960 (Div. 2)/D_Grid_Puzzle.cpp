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

bool check(int l, int r, vector<int> &a) {
    for (int i = l + 1; i < r; i++) {
        if (2 < a[i] && a[i] <= 4) {
            continue;
        }
        return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), f(n + 1);
    int p = 0;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1 || a[i] == 2) {
            pre[i] = p;
            p = i;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            f[i] = f[i - 1];
            continue;
        }
        f[i] = f[i - 1] + 1;
        if (i >= 2 && a[i] <= 2 && a[i - 1] <= 2) {
            f[i] = min(f[i], f[i - 2] + 1);
        }
        if (pre[i] && i - pre[i] > 2 && (i - pre[i]) % 2 && check(pre[i], i, a)) {
            f[i] = min(f[i], f[pre[i] - 1] + i - pre[i]);
        }
    }

    cout << f[n] << '\n';
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