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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    
    set<int> opt;
    for (int i = 0; i < m; i++) {
        int ind;
        cin >> ind;
        opt.insert(ind);
    }
    cin >> t;
    sort(t.begin(), t.end());

    int p = 0;
    for (auto x : opt) {
        s[x - 1] = t[p];
        p++;
    }
    cout << s << '\n';
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