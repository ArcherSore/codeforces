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
    vector<int> mxheight(n);
    mxheight[0] = v[0];
    for (int i = 1; i < n; i++) {
        mxheight[i] = max(mxheight[i - 1], v[i]);
    }
    vector<int> mnheight(n);
    mnheight[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        mnheight[i] = min(mnheight[i + 1], v[i]);
    }

    vector<int> ans(n);
    ans[n - 1] = mxheight[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        int l = mxheight[i];
        int r = mnheight[i + 1];
        if (l > r) {
            ans[i] = ans[i + 1];
        } else {
            ans[i] = mxheight[i];
        }
    }

    for (int  x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}