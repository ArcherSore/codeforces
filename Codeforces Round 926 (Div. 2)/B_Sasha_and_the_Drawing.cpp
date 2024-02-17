#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
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
    if (k <= 4 * (n - 1)) {
        cout << (k + 1) / 2 << '\n';
    } else if (k == 4 * n - 3) {
        cout << 2 * n - 1 << '\n';
    } else {
        cout << 2 * n << '\n';
    }
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