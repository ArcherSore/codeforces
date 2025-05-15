#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    LL sum = 0;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
        sum += x;
    }
    int mx = *max_element(v.begin(), v.end());
    int mn = *min_element(v.begin(), v.end());
    int cnt = count(v.begin(), v.end(), mx);

    if (mx - mn > k + 1) {
        cout << "Jerry";
    } else if (mx - mn == k + 1) {
        if (cnt == 1) {
            if (sum % 2) {
                cout << "Tom";
            } else {
                cout << "Jerry";
            }
        } else {
            cout << "Jerry";
        }
    } else {
        if (sum % 2) {
            cout << "Tom";
        } else {
            cout << "Jerry";
        }
    }
    cout << '\n';
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