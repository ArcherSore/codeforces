#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
        cnt[i] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        int tot = 0;
        for (int j = i + 1; j < n; j++) {
            if (v[j] > v[i]) {
                tot++;
            }
        }
        cnt[i] += tot;
    }
    cout << *min_element(cnt.begin(), cnt.end()) << '\n';
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