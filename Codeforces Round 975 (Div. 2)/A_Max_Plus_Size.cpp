// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    int maxx = 0, p = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x > maxx) {
            maxx = x;
            p = i % 2;
        } else if (x == maxx) {
            if (i % 2) {
                p = i % 2;
            }
        }
    }

    if (n % 2) {
        cout << maxx + n / 2 + p << '\n';
    } else {
        cout << maxx + n / 2 << '\n';
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