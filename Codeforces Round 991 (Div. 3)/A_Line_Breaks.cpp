#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    int tot = 0;
    for (auto &x : s) {
        cin >> x;
    }
    for (int i = 0; i < s.size(); i++) {
        tot += s[i].size();
        if (tot > m) {
            cout << i << '\n';
            return;
        }
    }
    cout << n << '\n';
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