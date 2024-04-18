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
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    
    int last = -1, ones = 0;
    for (auto [x, num] : a) {
        if (x != last + 1) {
            cout << last + 1 << '\n';
            return;
        }
        last = x;
        if (num == 1 && ++ones == 2) {
            cout << x << '\n';
            return;
        }
    }
    cout << (*a.rbegin()).first + 1 << '\n';
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