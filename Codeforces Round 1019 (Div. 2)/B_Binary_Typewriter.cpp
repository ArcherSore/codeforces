#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int p = 0;
    while (p < n && s[p] != '1') {
        p++;
    }
    if (p < n) {
        int t = p;
        while (p < n && s[p] != '0') {
            p++;
        }
        if (p < n) {
            while (p < n && s[p] != '1') {
                p++;
            }
            reverse(s.begin() + t, s.begin() + p);
        }
    }

    // cout << s << ' ';
    
    char d = '0';
    int res = 0;
    for (int i = 0; i < n; i++) {
        res++;
        if (s[i] != d) {
            res++;
            d = s[i];
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