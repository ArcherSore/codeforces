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
    string s, t;
    cin >> s;

    t += s[0];
    for (int i = 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '0') {
            continue;
        }
        t += s[i];
    }

    int z0 = 0, z1 = 0;
    for (auto c : t) {
        if (c == '0') {
            z0 += 1;
        } else {
            z1 += 1;
        }
    }

    if (z0 >= z1) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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