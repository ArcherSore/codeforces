#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cnt(m);
    int j = 0;
    for (int i = 0; i < n; i++) {
        cnt[j]++;
        j = (j + 1) % m;
    }
    if ((n - cnt[0]) > k) {
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