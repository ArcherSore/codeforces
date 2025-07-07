#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(a.begin(), a.end());

    LL ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int le = j + 1, ri = n - 1, mid;
            int r1 = -1;
            while (le <= ri) {
                mid = (le + ri) / 2;
                if (a[i] + a[j] > a[mid]) {
                    r1 = mid;
                    le = mid + 1;
                } else {
                    ri = mid - 1;
                }
            }
            le = j + 1, ri = n - 1;
            int r2 = -1;
            while (le <= ri) {
                mid = (le + ri) / 2;
                if (a[i] + a[j] + a[mid] > a.back()) {
                    r2 = mid;
                    ri = mid - 1;
                } else {
                    le = mid + 1;
                }
            }

            if (r1 != -1 && r2 != -1 && r1 >= r2) {
                ans += r1 - r2 + 1;
            }
        }
    }

    cout << ans << '\n';
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