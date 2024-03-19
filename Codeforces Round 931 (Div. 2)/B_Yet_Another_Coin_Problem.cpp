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
    int n;
    cin >> n;

    int res = 0x3f3f3f3f;
    for (int i = 0; i <= 2; i++) {
        for (int j = 0; j <= 1; j++) {
            for (int p = 0; p <= 4; p++) {
                for (int q = 0; q <= 2; q++) {
                    int t = 1 * i + 3 * j + 6 * p + 10 * q;
                    if (t > n) {
                        continue;
                    }
                    if ((n - t) % 15 == 0) {
                        res = min(res, i + j + p + q + (n - t) / 15);
                    }
                }
            }
        }
    }

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