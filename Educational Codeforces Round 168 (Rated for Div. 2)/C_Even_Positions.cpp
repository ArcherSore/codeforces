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

    int ans = 0;
    stack<int> s;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '_') {
            if (s.empty()) {
                s.push(i);
            } else {
                ans += i - s.top();
                s.pop();
            }
        } else if (c == '(') {
            s.push(i);
        } else {
            ans += i - s.top();
            s.pop();
        }
    }
    cout << ans << '\n';
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