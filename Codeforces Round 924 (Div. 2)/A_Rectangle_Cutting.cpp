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
    int a, b;
    cin >> a >> b;

    if ((!(a & 1) && a / 2 != b) || (!(b & 1) && b / 2 != a)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
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