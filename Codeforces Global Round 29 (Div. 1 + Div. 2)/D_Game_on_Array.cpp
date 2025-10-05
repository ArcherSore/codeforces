#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        if (x & 1) {
            mp[x]++;
            sum += x - 1;
        } else {
            sum += x;
        }
    }
    map<int, int, greater<int>> cnt;
    for (auto [x, c] : mp) {
        cnt[c]++;
    }
    ll a = sum / 2, b = sum / 2;
    // cerr << a << ' ' << b << '\n';
    int turn = 0;
    for (auto [x, c] : cnt) {
        while (c--) {
            if (turn) {
                b += x;
            } else {
                a += x;
            }
            turn ^= 1;
        }
    }
    cout << a << ' ' << b << '\n';
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