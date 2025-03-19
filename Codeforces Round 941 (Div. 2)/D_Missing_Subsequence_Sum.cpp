#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const LL INF = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    int p = __lg(k);
    vector<int> a;
    if (k > 1) {
        // construct 1~k-1
        if (k - 1 >= 1) {
            for (int i = 0; i < p; i++) {
                a.push_back((1 << i));
            }
            if (k - (1 << p) > 0) {
                a.push_back(k - (1 << p));
            }
        }
    }
    // construct k~n
    if (n > k) {
        a.push_back(k + 1);
    }
    if (n > 2 * k) {
        a.push_back(2 * k + 1);
    }
    if (n > 3 * k) {
        int r = 3 * k;
        while (r < n) {
            a.push_back(r + 1);
            r += r + 1;
        }
    }
    
    cout << a.size() << '\n';
    for (auto x : a) {
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