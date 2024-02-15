#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

bool ok(vector<int> &x, vector<int> &y, int n, int k) {
    int l = 0, r = 0, tl, tr;
    for (int i = 0; i < n; i++) {
        tl = l - k, tr = r + k;
        l = max(tl, x[i]);
        r = min(tr, y[i]);
        if (r < x[i] || l > y[i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    int mx = 0; // 记录最远的坐标
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        mx = max(mx, y[i]);
    }

    int l = 0, r = mx, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (ok(x, y, n, mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}