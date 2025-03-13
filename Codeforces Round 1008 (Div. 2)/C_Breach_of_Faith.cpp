#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> a(2 * n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());
    
    vector<LL> res(2 * n + 1);
    LL mx = 0, mn = 0;
    for (int i = 0; i < n - 1; i++) {
        mn += a[i];
        res[2 * i + 1] = a[i];
    }
    for (int i = n - 1; i < 2 * n; i++) {
        mx += a[i];
        res[2 * (i - n + 1)] = a[i];
    }
    res[2 * n - 1] = mx - mn;
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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