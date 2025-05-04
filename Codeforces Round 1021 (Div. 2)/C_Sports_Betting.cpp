#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    int lst = -1;
    set<int> ct;
    for (auto [d, x] : cnt) {
        if (x >= 4) {
            cout << "Yes\n";
            return;
        } else if (x == 3 || x == 2) {
            if (ct.find(d + 1) != ct.end()) {
                cout << "Yes\n";
                return;
            } else {
                ct.insert(d + 2);
            }
        } else if (x == 1) {
            if (ct.find(d + 1) != ct.end()) {
                ct.insert(d + 2);
            }
        }
    }
    cout << "No\n";
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