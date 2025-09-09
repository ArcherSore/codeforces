#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    ll k, x;
    cin >> k >> x;
    ll tot = (1LL << k + 1);
    ll y = tot - x;

    vector<int> res;
    while (x != y) {
        if (x > y) {
            res.push_back(2);
            y *= 2;
            x = tot - y;
        } else if (x < y) {
            res.push_back(1);
            x *= 2;
            y = tot - x;
        }
    }
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';
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