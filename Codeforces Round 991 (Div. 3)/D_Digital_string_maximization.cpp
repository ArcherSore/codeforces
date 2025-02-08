#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int p = i, mx = s[i] - '0';
        for (int j = i + 1; j < min((int)s.size(), i + 9); j++) {
            if (s[j] - '0' - (j - i) > mx) {
                mx = s[j] - '0' - (j - i);
                p = j;
            }
        }
        for (int j = p; j > i; j--) {
            swap(s[j], s[j - 1]);
        }
        s[i] = mx + '0';
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