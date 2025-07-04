#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    int res = 1;
    set<int> pt, tot;
    pt.insert(v[0]);
    for (int i = 1; i < n; i++) {
        if (pt.find(v[i]) != pt.end()) {
            pt.erase(v[i]);
        }
        tot.insert(v[i]);

        if (pt.size() == 0) {
            pt = tot;
            tot.clear();
            res++;
        }
    }
    cout << res << '\n';
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