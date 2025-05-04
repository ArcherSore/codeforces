#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    if ((n - k) % 2) {
        // set<int> s;
        // for (int i = (1 + n - k) / 2; i <= (k + 1 + n) / 2; i++) {
        //     s.insert(v[i]);
        // }
        // cout << s.size() << '\n';
        k--;
    }
    cout << v[(k + 1 + n + 1) / 2] - v[(n - k) / 2] + 1 << '\n';
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