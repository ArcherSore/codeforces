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
    int n;
    cin >> n;
    LL d, x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (!i) {
            d = x;
        } else {
            d = (d / x + 1) * x;
        }
    }
    cout << d << '\n';
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