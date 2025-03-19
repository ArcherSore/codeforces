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
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    n = v.size(); 
    int flag = 1;
    int pre = 0;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == pre + 1) {
            flag = 1 - flag;
        } else {
            break;
        }
        pre = v[i];
    }
    if (flag) {
        cout << "Alice\n";
    } else {
        cout << "Bob\n";
    }
    return;
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