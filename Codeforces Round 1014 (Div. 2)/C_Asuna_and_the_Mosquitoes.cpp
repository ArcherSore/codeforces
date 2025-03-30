#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    
    int od = 0, ev = 0;
    for (auto x : v) {
        if (x % 2) {
            od = 1;
        } else {
            ev = 1;
        }
    }

    if (!od || !ev) {
        cout << *max_element(v.begin(), v.end()) << '\n';
        return;
    }

    LL avai = 0;
    for (LL x : v) {
        if (x % 2) {
            avai += x - 1;
        } else {
            avai += x;
        }
    }
    cout << 1 + avai << '\n';
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