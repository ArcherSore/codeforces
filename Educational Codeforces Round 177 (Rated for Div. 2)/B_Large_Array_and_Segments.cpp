#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, k, x;
    cin >> n >> k >> x;
    vector<LL> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<LL> suf(n + 1);
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + a[i];
    }
    LL sum = suf[0];
    
    LL le = 1, ri = n * k, mid;
    LL res = 0;
    while (le <= ri) {
        mid = (le + ri) / 2;
        if (sum * (k - (mid + n - 1) / n) + suf[(mid - 1) % n] >= x) {
            res = mid;
            le = mid + 1;
        } else {
            ri = mid - 1;
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