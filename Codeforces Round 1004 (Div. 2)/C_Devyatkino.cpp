#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

vector<int> a = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

bool check(LL n) {
    while (n) {
        if (n % 10 == 7) {
            return true;
        }
        n /= 10;
    }
    return false;
}

void solve() {
    LL n;
    cin >> n;
    if (check(n)) {
        cout << "0\n";
        return;
    }
    int res = 10;
    for (auto x : a) {
        LL t = n;
        for (int i = 1; i <= 9; i++) {
            t += x;
            if (check(t)) {
                res = min(res, i);
                break;
            }
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