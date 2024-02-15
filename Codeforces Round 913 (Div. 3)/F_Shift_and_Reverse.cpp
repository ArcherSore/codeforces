#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

typedef long long LL;
const int INF = 1e9;

int cal(vector<int> &a, int n) {
    vector<int> t(2 * n);
    for (int i = 0; i < n; i++) {
        t[i] = a[i];
        t[i + n] = a[i];
    }
    
    int cnt = 1, res = INF;
    for (int i = 2 * n - 2; i >= 0; i--) {
        if (t[i] >= t[i + 1]) {
            cnt++; 
        } else {
            cnt = 1;
        }

        if (cnt == n) {
            res = min(res, n - i + 1);
        }
    }

    cnt = 1;
    for (int i = 2 * n - 2; i >= 0; i--) {
        if (t[i] <= t[i + 1]) {
            cnt++; 
        } else {
            cnt = 1;
        }

        if (cnt == n) {
            res = min(res, n - i);
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    int ans = INF;
    ans = cal(a, n);
    reverse(a.begin(), a.end());
    ans = min(ans, cal(a, n) + 1);
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
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