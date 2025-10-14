#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    vector<int> seq(2 * n + 3);
    for (int i = 1; i <= 2 * n + 2; i++) {
        cin >> seq[i];
    }

    vector<char> s(n + 1);
    s[0] = 'a';
    for (int i = 2; i <= 2 * n + 2; i += 2) {
        if (seq[i] != 1) {
            s[i / 2] = s[i / 2 - 1];
        } else {
            s[i / 2] = (s[i / 2 - 1] == 'a' ? 'b' : 'a');
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << s[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}