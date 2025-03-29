#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) {
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