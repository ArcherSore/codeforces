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
    vector<int> a(n);
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i] >> 2].push(a[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << mp[a[i] >> 2].top() << ' ';
        mp[a[i] >> 2].pop();
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