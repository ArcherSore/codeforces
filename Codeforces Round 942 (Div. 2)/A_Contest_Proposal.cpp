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
    deque<int> a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b.push_back(x);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (b.front() < a.front()) {
            res++;
            a.pop_back();
            b.pop_front();
        } else {
            a.pop_front();
            b.pop_front();
        }
    }
    cout << res << '\n';
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