#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    LL _a,  mx;

    for (int i = 1; i < n; i++) {
        a[i] -= a[0];
    }
    a[0] = 0;
    // 求一组数的gcd
    LL g = a[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i]);
    }

    _a = -1; // a(n + 1) 的值
    for (int i = 1; i < n; i++) {
        a[i] /= g;
        if (a[i] > a[i - 1] + 1) {
            _a = a[i] - 1;
        }
    }
    if (_a == -1) {
        _a = a[n - 1] + 1;
        mx = _a;
    } else {
        mx = a[n - 1];
    }
    a.push_back(_a);

    // 求sum(ai)
    LL sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += a[i];
    }

    LL op = (n + 1) * mx - sum;
    cout << op << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}