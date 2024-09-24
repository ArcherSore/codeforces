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
    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    int cnt = (n - 1) / 5 + 1, rest = n % 5 == 0 ? 5 : n % 5 - 1;
    for (int i = 0; i < 5; i++) {
        if (i <= rest) {
            for (int j = 0; j < cnt; j++) {
                cout << v[i];
            }
        } else {
            for (int j = 0; j < cnt - 1; j++) {
                cout << v[i];
            }
        }
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