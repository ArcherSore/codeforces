#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <numeric>
#include <set> 
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }

    cin >> q;
    while (q--) {
        int st, u;
        cin >> st >> u;

        int l = st, r = n, mid;
        while (l < r) {
            mid = (l + r + 1) / 2;
            if (1.0 * (sum[mid] - sum[st - 1]) <= 1.0 * (2 * u + 1) / 2) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (r != n && 1.0 * (sum[r + 1] - sum[st - 1]) - 1.0 * (2 * u + 1) / 2 < 1.0 * (2 * u + 1) / 2 - 1.0 * (sum[r] - sum[st - 1])) {
            r += 1;
        }
        cout << r << " ";
    }
    cout << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}