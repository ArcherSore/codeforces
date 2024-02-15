#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> c(n + 2);
    vector<long long> dif(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    c[n + 1] = 1;
    int ans = 0;
    for (int i = 2; i <= n + 1; i++) {
        dif[i - 1] = c[i] - c[i - 1];
        if (dif[i - 1] < 0) {
            ans += (-dif[i - 1]);
        }
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}