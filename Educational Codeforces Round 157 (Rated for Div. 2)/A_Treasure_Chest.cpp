#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    if (y < x) {
        cout << x << endl;
    } else if (x + k >= y) {
        cout << y << endl;
    } else {
        cout << x + k + 2 * (y - x - k) << endl;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}