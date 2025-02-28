#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<string> v(n - 3);
    int cnt = 0;
    for (int i = 0; i < n - 3; i++) {
        v[i] = s.substr(i, 4);
        if (v[i] == "1100") {
            cnt++;
        }
    }
    int m;
    cin >> m;
    while (m--) {
        int p, vl;
        cin >> p >> vl;
        p--;
        for (int i = max(0, p - 3); i <= min(p, n - 4); i++) {
            string tmp = v[i];
            v[i][p - i] = '0' + vl;
            if (tmp == "1100" && v[i] != "1100") {
                cnt--;
            }
            if (tmp != "1100" && v[i] == "1100") {
                cnt++;
            }
        }
        if (cnt) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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