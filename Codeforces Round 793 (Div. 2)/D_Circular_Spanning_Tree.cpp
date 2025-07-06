#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int cnt = count(s.begin(), s.end(), '1');
    if (cnt % 2 == 1 || cnt == 0) {
        cout << "NO\n";
        return;
    }
    
    int p;
    for (p = 0; p < n; p++) {
        if (s[(p - 1 + n) % n] == '1') {
            break;
        }
    }
    cout << "YES\n";
    for (int i = (p - 1 + n) % n; i != p; i = (i - 1 + n) % n) {
        if (s[(i - 1 + n) % n] == '1') {
            cout << i + 1 << ' ' << p + 1 << '\n';
        } else {
            cout << i + 1 << ' ' << (i - 1 + n) % n + 1 << '\n';
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}