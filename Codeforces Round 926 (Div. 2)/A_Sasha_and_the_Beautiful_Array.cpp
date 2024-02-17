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
    int minn = 1e9 + 1, maxx = 0;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        minn = min(minn, x);
        maxx = max(maxx, x);
    }
    cout << maxx - minn << '\n';
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