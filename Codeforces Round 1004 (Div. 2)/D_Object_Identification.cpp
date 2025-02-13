#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), vis(n + 1);
    for (auto &x : v) {
        cin >> x;
        vis[x]++;
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0) {
            // case1
            if (i == 1) {
                cout << "? 1 2" << endl;
            } else {
                cout << "? " << i << ' ' << i - 1 << endl;
            }
            int opt;
            cin >> opt;
            if (opt == 0) {
                cout << "! A" << endl;
            } else {
                cout << "! B" << endl;
            }
            return;
        }
    }
    // case2
    int id1, id2;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            id1 = i + 1;
        }
        if (v[i] == n) {
            id2 = i + 1;
        }
    }
    int opt1, opt2;
    cout << "? " << id1 << ' ' << id2 << endl;
    cin >> opt1;
    cout << "? " << id2 << ' ' << id1 << endl;
    cin >> opt2;
    if (opt1 != opt2) {
        cout << "! A" << endl;
    } else {
        if (opt1 >= n - 1) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
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