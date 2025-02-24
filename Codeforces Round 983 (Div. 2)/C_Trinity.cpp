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
    sort(v.begin(), v.end());
    vector<int> res(n);
    for (int i = 0; i < n - 1; i++) {
        auto p = lower_bound(v.begin(), v.end(), v[i] + v[i + 1]);
        int cnt = v.end() - p;
        res[i] = cnt + i;
    }
    res[n - 1] = n;
    cout << *min_element(res.begin(), res.end()) << '\n';
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