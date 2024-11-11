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
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    int overlap = 0;
    for (int i = 0; i < min(n, m); i++) {
        if (s[i] == t[i]) {
            overlap += 1;
        } else {
            break;
        }
    }
    if (overlap) {
        overlap -= 1;
    }
    cout << n + m - overlap << '\n';
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