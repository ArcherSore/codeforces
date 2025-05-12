#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

int work(int x) {
    int cnt = 0;
    while (x) {
        if (x & 1) {
            cnt++;
        }
        x >>= 1;
    }
    return cnt;
}

void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 1 && x == 0) {
        cout << -1 << '\n';
        return;
    }
    int cnt = work(x);
    if (cnt >= n) {
        cout << x << '\n';
    } else {
        if (cnt - (x & 1) == 0) {
            cout << x + (n - cnt) + ((n - cnt) % 2 ? 3 : 0) << '\n';
        } else {
            cout << x + (n - cnt) + (n - cnt) % 2 << '\n';
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