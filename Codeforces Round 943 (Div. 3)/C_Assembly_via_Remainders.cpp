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
    vector<int> a(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> res(n + 1);
    res[1] = a[2] + 1;
    for (int i = 2; i <= n; i++) {
        res[i] = res[i - 1] + a[i];
        if (i != n) {
            while (res[i] <= a[i + 1]) {
                res[i] += res[i - 1];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << '\n';
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