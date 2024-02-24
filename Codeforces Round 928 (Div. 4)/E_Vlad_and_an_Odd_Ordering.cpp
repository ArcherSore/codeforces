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
    int n, k;
    cin >> n >> k;

    for (int i = 1; ; i *= 2) {
        int num = (n + i) / 2 / i;
        if (num >= k) {
            cout << i * (2 * k - 1) << '\n';
            break;
        } else {
            k -= num;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen(".out", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}