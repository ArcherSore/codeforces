#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int flag = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout << "NO\n";
        return;
    }
    
    string t = s;
    reverse(t.begin(), t.end());

    if (s < t) {
        cout << "YES\n";
        return;
    }

    if (k > 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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