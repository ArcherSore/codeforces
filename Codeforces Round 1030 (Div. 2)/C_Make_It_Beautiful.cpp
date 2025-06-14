#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, k;
    cin >> n >> k;
    vector<int> p(61);
    int res = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        for (int j = 0; j <= 60; j++) {
            if (((1LL * x >> j) & 1) == 0) {
                p[j]++;
            } else {
                res++;
            }
        }
    }
    
    for (int i = 0; i < 61; i++) {
        while (k && p[i]) {
            if (k >= (1LL << i)) {
                k -= (1LL << i);
                p[i]--;
                res++;
            } else {
                break;
            }
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