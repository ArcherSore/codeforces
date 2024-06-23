#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;

const int N = 1e6 + 10;

LL n, m, k, x, y, z, a[N];

void solve() {
    cin >> n >> m;
    if (m % 2) {
        cout << "NO" << endl;
    } else {
        LL r = n;
        for (LL i = 1; i <= r; i++) {
            if (2 * abs(r - i) <= m) {
                a[i] = r;
                a[r] = i;
                m -= 2 * abs(r - i);
                r--;
            } else {
                a[i] = i;
            }
        }
        if (m) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (LL i = 1; i <= n; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}
