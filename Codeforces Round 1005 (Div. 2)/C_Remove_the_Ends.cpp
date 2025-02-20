#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v;
    for (int i = 0; i < n; i++) {
        LL x;
        cin >> x;
        if (v.empty() || v.back() * x < 0) {
            v.push_back(x);
        } else {
            v.back() += x;
        }
    }
    n = v.size();
    
    vector<LL> pre(n), suf(n);
    pre[0] = (v[0] > 0 ? v[0] : 0);
    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (v[i] > 0 ? v[i] : 0);
    }
    suf[n - 1] = (v[n - 1] < 0 ? -v[n - 1] : 0);
    for (int i = n - 2; i >= 0; i--) {
        suf[i] = suf[i + 1] - (v[i] < 0 ? v[i] : 0);
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        res = max(res, pre[i] + suf[i]);
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