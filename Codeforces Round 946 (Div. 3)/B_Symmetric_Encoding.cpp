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
    set<char> ss;
    for (auto c : s) {
        ss.insert(c);
    }
    vector<char> t;
    for (auto c : ss) {
        t.push_back(c);
        // cout << c << ' ';
    }
    for (auto c : s) {
        int p = lower_bound(t.begin(), t.end(), c) - t.begin();
        n = t.size() - 1;
        cout << t[n - p];
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