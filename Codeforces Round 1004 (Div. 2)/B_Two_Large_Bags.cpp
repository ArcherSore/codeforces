#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x]++;
    }

    int mn = (*v.begin()).first, mx = (*v.rbegin()).first;
    for (int i = mn; i <= mx; i++) {
        if (v[i] >= 2) {
            v[i + 1] += v[i] - 2;
        }
        if (v[i] == 1) {
            cout << "No\n";
            return;
        }
    }
    if (v[mx + 1] % 2) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
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