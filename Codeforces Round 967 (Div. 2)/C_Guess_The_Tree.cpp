#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    vector<PII> res;
    for (int i = 2; i <= n; i++) {
        int u = 1, v = i;
        while (true) {
            cout << "? " << u << ' ' << v << endl;
            int mid;
            cin >> mid;
            if (mid == u || mid == v) {
                res.push_back({u, v});
                break;
            }
            u = mid;
        }
    }
    cout << "! ";
    for (auto [u, v] : res) {
        cout << u << ' ' << v << ' ';
    }
    cout << endl;
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