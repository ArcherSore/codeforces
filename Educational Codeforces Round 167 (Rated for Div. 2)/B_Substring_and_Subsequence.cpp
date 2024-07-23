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
    
    int cs = 0;
    for (int i = 0; t[i]; i++) {
        int p = i, cnt = 0;
        for (int j = 0; s[j] && t[p]; j++) {
            if (s[j] == t[p]) {
                p++, cnt++;
            }
        }
        cs = max(cs, cnt);
    }

    cout << n + m - cs << '\n';
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