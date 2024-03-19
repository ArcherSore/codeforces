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
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(n + 1);
    vector<LL> s1(n + 1), s2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s1[i] = s1[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        s2[i] = s2[i - 1] + b[i];
    }

    LL res = 0, minn = 0;
    int up = 1;
    for (int i = n; i > m; i--) {
        if (b[i] <= a[i]) {
            res += b[i];
            up = 0;
        } else {
            res += a[i];
            up = 1;
        }
    }
    // cout << res << '\n';

    minn = 1e18;
    for (int i = 1; i <= m; i++) {
        LL t = a[i] + s2[m] - s2[i];
        minn = min(minn, t);
    }
    res += minn;
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}