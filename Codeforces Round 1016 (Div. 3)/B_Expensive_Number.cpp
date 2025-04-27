#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    
    int res = 0, p = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '0') {
            p = i;
            break;
        }
        res++;
    }
    for (int i = 0; i < p; i++) {
        if (s[i] != '0') {
            res++;
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