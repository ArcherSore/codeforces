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
    string s;
    cin >> s;
    if (s[0] == '1' || s[n - 1] == '1') {
        cout << "YES\n";
        return;
    }
    s.push_back('0');
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            ones++;
        } else {
            if (ones >= 2) {
                cout << "YES\n";
                return;
            }
            ones = 0;
        }
    }
    cout << "NO\n";
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