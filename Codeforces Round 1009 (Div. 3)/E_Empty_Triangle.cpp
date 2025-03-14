#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;

    int a = 1, b = 2, c = 3;
    while (true) {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        int rp;
        cin >> rp;
        if (rp == 0) {
            break;
        }
        int p = rand() % 3;
        if (p == 0) {
            a = rp;
        } else if (p == 1) {
            b =rp;
        } else {
            c = rp;
        }
    }
    cout << "! " << a << ' ' << b << ' ' << c << endl;
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