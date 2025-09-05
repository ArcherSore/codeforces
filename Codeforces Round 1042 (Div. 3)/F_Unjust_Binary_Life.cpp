#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

ll calc(vector<ll> &a, vector<ll> &b) {
    int n = a.size(), p = 0;
    ll pre = 0, post = accumulate(b.begin(), b.end(), 0LL);
    ll res = 0;
    for (int i = 0; i < n; i++) {
        while (p < n && a[i] > b[p]) {
            pre += b[p];
            post -= b[p];
            p++;
        }
        res += (p * a[i] - pre) + (post - (n - p) * a[i]); 
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    // a0, a1, b0, b1
    vector<array<ll, 4>> cnt(n);
    if (a[0] == '0') {
        cnt[0][0] = 1;
    } else {
        cnt[0][1] = 1;
    }
    if (b[0] == '0') {
        cnt[0][2] = 1;
    } else {
        cnt[0][3] = 1;
    }
    for (int i = 1; i < n; i++) {
        cnt[i][0] = cnt[i - 1][0] + (a[i] == '0');
        cnt[i][1] = cnt[i - 1][1] + (a[i] == '1');
        cnt[i][2] = cnt[i - 1][2] + (b[i] == '0');
        cnt[i][3] = cnt[i - 1][3] + (b[i] == '1');
    }

    vector<ll> pre1(n), pre2(n);
    for (int i = 0; i < n; i++) {
        pre1[i] = cnt[i][0] - cnt[i][1];
        pre2[i] = cnt[i][3] - cnt[i][2];
    }
    sort(pre1.begin(), pre1.end());
    sort(pre2.begin(), pre2.end());

    // cerr << calc(pre1, pre2) << '\n';
    ll res = 1LL * n * n * (n + 1) / 2 - calc(pre1, pre2) / 2;
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