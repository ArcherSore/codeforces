#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    
    for (int i = 0; i < (n + 1) / 2 - 1; i++) {
        if ((v[i] == v[i + 1]) + (v[n - i - 1] == v[n - i - 2]) > (v[i] == v[n - i - 2]) + (v[i + 1] == v[n - i - 1])) {
            swap(v[i + 1], v[n - i - 2]);
        }
    }

    int res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == v[i + 1]) {
            res++;
        }
    }
    cout << res << '\n';
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