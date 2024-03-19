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
using PII = pair<int, int>;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b % 3 && b % 3 + c < 3) {
        cout << -1 << '\n';
        return;
    }

    int res = a;
    int t = b + c;
    res += t / 3;
    t %= 3;
    res += (t == 0 ? 0 : 1);
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}