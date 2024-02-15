#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
const int INF = 2e9 + 1;

void solve() {
    int n;
    cin >> n;
    vector<LL> p(n + 2), pre(n + 2), suf(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    p[0] = -INF, p[n + 1] = INF;
    for (int i = 2; i <= n; i++) {
        if (p[i] - p[i - 1] < p[i - 1] - p[i - 2]) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1] + (p[i] - p[i - 1]);
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        if (p[i + 1] - p[i] < p[i + 2] - p[i + 1]) {
            suf[i] = suf[i + 1] + 1;
        } else {
            suf[i] = suf[i + 1] + (p[i + 1] - p[i]);
        }
    }
    int q, x, y;
    cin >> q;
    while (q--) {
        cin >> x >> y;
        if (x < y) {
            cout << pre[y] - pre[x] << '\n';
        } else {
            cout << suf[y] - suf[x] << '\n';
        }
    }
    return;
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