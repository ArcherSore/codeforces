#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    LL n, k;
    cin >> n >> k;
    
    if (n <= 41 && k > (1LL << n - 1)) {
        cout << -1 << '\n';
        return;
    }

    int p = n, c = 1;
    int l = 0, r = n - 1;
    vector<int> res(n);
    while (p > 1) {
        if (p > 42) {
            res[l++] = c++;
        } else {
            if (k <= (1LL << p - 2)) {
                res[l++] = c++;
            } else {
                res[r--] = c++;
                k -= (1LL << p - 2);
            }
        }
        p--;
    }
    res[l] = c;

    for (auto &x : res) {
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