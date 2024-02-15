#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> d(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        ans = max(ans, d[i] - d[i - 1]);
    }
    ans = max(ans, 2 * (x - d[n]));
    cout << ans << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}