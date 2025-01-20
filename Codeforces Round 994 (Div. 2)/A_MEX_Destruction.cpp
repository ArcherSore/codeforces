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
    vector<int> v(n);
    int flag = 0, cnt = 0, zeros = 1;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i]) {
            zeros = 0;
            flag = 1;
        } else {
            if (flag) {
                cnt += 1;
            }
            flag = 0;
        }
    }
    if (flag) {
        cnt += 1;
    }

    if (zeros) {
        cout << 0 << '\n';
    } else {
        if (cnt == 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
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