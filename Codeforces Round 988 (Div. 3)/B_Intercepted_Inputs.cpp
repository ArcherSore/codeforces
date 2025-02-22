#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x]++;
    }
    n -= 2;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            int j = n / i;
            if (i == j && mp[i] >= 2) {
                cout << i << ' ' << j << '\n';
                return;
            }
            if (i != j && mp[i] && mp[j]) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
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