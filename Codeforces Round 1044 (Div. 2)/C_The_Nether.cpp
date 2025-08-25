#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> len(n + 1);
    for (int i = 0; i < n; i++) {
        cout << "? " << i + 1 << ' ' << n;
        for (int j = 1; j <= n; j++) {
            cout << ' ' << j;
        }
        cout << endl;

        int l;
        cin >> l;
        len[l].push_back(i + 1);
    }
    
    vector<int> res;
    int i = n;
    while (i >= 0 && len[i].empty()) {
        i--;
    }
    int st = len[i][0];
    res.push_back(st);
    for (i = i - 1; i > 0; i--) {
        for (int j : len[i]) {
            cout << "? " << st << ' ' << 2 << ' ' << st << ' ' << j << endl;
            int l;
            cin >> l;
            if (l == 2) {
                st = j;
                res.push_back(st);
                break;
            }
        }
    }

    cout << "! " << res.size();
    for (int x : res) {
        cout << ' ' << x;
    }
    cout << endl;
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