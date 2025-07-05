#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int w, h, a, b;
    cin >> w >> h >> a >> b;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (x1 == x2) {
        if (abs(y1 - y2) % b == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    if (x1 > x2) {
        swap(x1, x2);
        swap(y1, y2);
    }
    if (x1 + a <= x2) {
        if (y1 != y2 && abs(y1 - y2) % b == 0 || abs(x1 - x2) % a == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    } else {
        if (abs(y1 - y2) % b == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
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