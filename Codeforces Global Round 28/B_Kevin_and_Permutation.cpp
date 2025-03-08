#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    int t = 1;
    for (int i = k - 1; i < n; i += k) {
        p[i] = t;
        t++;
    }
    for (int i = 0; i < n; i++) {
        if (p[i]) {
            continue;
        }
        p[i] = t;
        t++;
    }
    for (auto x : p) {
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