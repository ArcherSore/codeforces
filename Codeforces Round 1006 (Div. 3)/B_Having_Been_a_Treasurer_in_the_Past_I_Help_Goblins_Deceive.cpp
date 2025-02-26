#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    LL cnt0 = 0, cnt1 = 0;
    for (auto c : s) {
        if (c == '-') {
            cnt0++;
        } else {
            cnt1++;
        }
    }
    LL p1 = cnt0 / 2, p2 = (cnt0 + 1) / 2;
    LL res = p1 * p2 * cnt1;
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