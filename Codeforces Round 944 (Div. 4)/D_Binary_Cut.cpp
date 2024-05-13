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

void find_longest(string &s) {
    int p = 0;
    int n = s.size();

    while (s[p] && s[p] != '0') {
        p++;
    }
    if (p == n) {
        return;
    }
    int maxlen = 0, l = n - 1, r = n - 1;
    for (int i = p + 1; i < n; i++) {
        if (s[i] == '0' && s[i - 1] == '1') {
            if (i - p > maxlen) {
                maxlen = i - p;
                l = p, r = i - 1;
            }
            p = i;
        }
    }
    if (s.back() == '1' && n - p > maxlen) {
        maxlen = n - p;
        l = p, r = n - 1;
    }

    s.erase(l, maxlen);
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    
    find_longest(s);
    // cout << s << '\n';

    int res = 0;
    if (n > s.size()) {
        res++;
    }
    char c = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != c) {
            res++;
            c = s[i];
        }
    }
    if (s.size()) {
        res++;
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