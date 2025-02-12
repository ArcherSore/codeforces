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
    set<int> s;
    for (int i = 1; i <= 100; i++) {
        s.insert((2 * i - 1) * (2 * i - 1));
    }
    int sum = 0, res = 0;
    for (auto x : v) {
        sum += x;
        if (s.find(sum) != s.end()) {
            res += 1;
        }
    }
    cout << res << '\n';
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