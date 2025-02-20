#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> best(n);
    for (int i = 0; i < n; i++) {
        int t = max(i * 2, (n - i - 1) * 2);
        best[i] = t + 1;
    }
    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
    } 
    for (int i = 0; i < n; i++) {
        if (v[i] < best[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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