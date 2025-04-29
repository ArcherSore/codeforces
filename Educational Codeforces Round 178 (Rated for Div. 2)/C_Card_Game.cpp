#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            a.push_back(i + 1);
        } else {
            b.push_back(i + 1);
        }
    }

    if (a[0] == 1) {
        if (b[0] == n) {
            cout << "Alice\n";
            return;
        }
        if (a.back() > b.back()) {
            cout << "Alice\n";
        } else {
            cout << "Bob\n";
        }
    } else {
        if (a.back() == n) {
            if (a.size() == 1) {
                cout << "Bob\n";
            } else {
                if (a[a.size() - 2] > b.back()) {
                    cout << "Alice\n";
                } else {
                    cout << "Bob\n";
                }
            }
        } else {
            if (a.back() > b.back()) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            }
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