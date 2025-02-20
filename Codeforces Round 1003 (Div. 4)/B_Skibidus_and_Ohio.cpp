#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int flag = 0;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == s[i + 1]) {
            flag = 1;
            break;;
        }
    }
    cout << (flag ? 1 : s.size()) << '\n';
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