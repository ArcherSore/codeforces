#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += a[i] - a[i - 1];
        ans += a[i + n] - a[i + n - 1];
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " " << a[i + n] << endl;
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