#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    for (int k = 1; k <= n / 2; k++) {
        set<pii> s;
        for (int i = 0; i < n; i++) {
            int j = (i + k) % n;
            if (!s.empty() && s.find({min(i, j), max(i, j)}) != s.end()) {
                break;
            }
            s.insert({min(i, j), max(i, j)});

            int res;
            cout << i + 1 << ' ' << j + 1 << endl;
            cin >> res;

            if (res == 1) {
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