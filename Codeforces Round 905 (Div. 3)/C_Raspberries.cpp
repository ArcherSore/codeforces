#include <iostream>
using namespace std;

int ind[6] = {0, 0, 200000, 200001, 200000, 200000};

void solve() {
    int n, k;
    cin >> n >> k;
    if (k != 4) {
        int ans = 100;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            if (x % k == 0) {
                ans = 0;
            } else{
                ans = min(ans, k - (x % k));
            }
            // cout << ans << endl;
        }
        cout << ans << endl;
    } else {
        int ans = 100;
        int odd = 0, even = 0;
        for (int i = 1, x; i <= n; i++) {
            cin >> x;
            if (x % k == 0) {
                ans = 0;
            } else{
                ans = min(ans, k - (x % k));
            }

            if (x % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        if (even >= 2) cout << 0 << endl;
        else if (even == 1 && odd >= 1) cout << min(ans, 1) << endl;
        else cout << min(ans, 2) << endl;
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