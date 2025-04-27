#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        if (v[i] <= k) {
            p[i] = 1;
        } else {
            p[i] = -1;
        }
    }
    
    int flag = 0, tmp = 0;
    // 左到右2
    for (int i = 0; i < n - 1; i++) {
        tmp += p[i];
        if (tmp >= 0 && p[i] == 1) {
            flag++;
        }
        if (flag == 2) {
            cout << "YES\n";
            return;
        }
    }

    flag = 0, tmp = 0;
    // 右到左2
    for (int i = n - 1; i >= 1; i--) {
        tmp += p[i];
        if (tmp >= 0 && p[i] == 1) {
            flag++;
        }
        if (flag == 2) {
            cout << "YES\n";
            return;
        }
    }
    
    // 左1右1
    int p1 = n - 1, p2 = 0;
    tmp = 0;
    for (int i = 0; i < n - 1; i++) {
        tmp += p[i];
        if (tmp >= 0 && p[i] == 1) {
            p1 = i;
            break;
        }
    }
    tmp = 0;
    for (int i = n - 1; i >= 1; i--) {
        tmp += p[i];
        if (tmp >= 0 && p[i] == 1) {
            p2 = i;
            break;
        }
    }
    if (p1 < p2 - 1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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