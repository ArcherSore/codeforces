#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (abs(v[i] - v[j]) % k == 0) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "YES\n" << i + 1 << '\n';
            return;
        }
    }
    cout << "NO\n";
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