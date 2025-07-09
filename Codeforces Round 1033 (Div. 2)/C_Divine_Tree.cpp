#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, m;
    cin >> n >> m;
    if (n > m || m > n * (n + 1) / 2) {
        cout << -1 << '\n';
        return;
    }

    LL need = m - n;
    vector<LL> v;
    for (LL i = n - 1; i > 0; i--) {
        if (need >= i) {
            v.push_back(i + 1);
            need -= i;
        }
    }
    if (v.empty() || v.back() != 1) {
        v.push_back(1);
        // vis[]
    }
    
    vector<int> vis(n + 1);
    cout << v[0] << '\n'; 
    vis[v[0]] = 1;
    for (int i = 1; i < v.size(); i++) {
        cout << v[i - 1] << ' ' << v[i] << '\n';
        vis[v[i - 1]] = vis[v[i]] = 1;
    }
    int pre = v.back();
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << pre << ' ' << i << '\n';
            pre = i;
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