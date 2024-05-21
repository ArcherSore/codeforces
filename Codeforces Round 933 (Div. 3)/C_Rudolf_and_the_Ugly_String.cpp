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

int string_find(string &s, string &t) {
    int res = 0;
    int p = s.find(t, 0);
    while (p != s.npos) {
        res++;
        p = s.find(t, p + 1);
    }
    return res;
} 

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s;

    int res = string_find(s, t = "map") + string_find(s, t = "pie") - string_find(s, t = "mapie");
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