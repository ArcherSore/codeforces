#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    int cnt = 0;
    if (x < y) {
        swap(a, b);
        swap(x, y);
    }
    if (k >= b) {
        cnt += (k - b) / y;
        k -= cnt * y;
        if (k >= b) {
            k -= y;
            cnt++;
        }
    }
    

    int c = 0;
    if (k >= a) {
        c = (k - a) / x;
        k -= c * x;
        if (k >= a) {
            c++;
        }
    }
    cout << cnt + c << '\n';
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