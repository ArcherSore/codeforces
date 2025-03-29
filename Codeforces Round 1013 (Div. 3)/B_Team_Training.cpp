#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    sort(v.rbegin(), v.rend());
    stack<LL> st;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] * (st.size() + 1) >= x) {
            res += 1;
            while (!st.empty()) {
                st.pop();
            }
        } else {
            st.push(v[i]);
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