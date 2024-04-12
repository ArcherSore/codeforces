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
    int n, a, b;
    cin >> n >> a >> b;
    if (1.0 * b / 2 >= 1.0 * a) {
        cout << a * n << '\n';
    } else {
        if (n % 2 == 0) {
            cout << n / 2 * b << '\n';
        } else {
            cout << n / 2 * b + a << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}