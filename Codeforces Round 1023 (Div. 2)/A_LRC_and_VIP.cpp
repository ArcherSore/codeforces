#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    if (count(v.begin(), v.end(), v[0]) == n) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        int mx = *max_element(v.begin(), v.end());
        for (auto x : v) {
            if (x != mx) {
                cout << 1 << ' ';
            } else {
                cout << 2 << ' ';
            }
        }
        cout << '\n';
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