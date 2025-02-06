#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    map<int, int> a, b;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        a[x]++;
    }
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        b[x]++;
    }

    if (a.size() * b.size() >= 3) {
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