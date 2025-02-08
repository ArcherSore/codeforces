#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;

    map<int, int> cnt;
    int sum = 0;
    for (char c : s) {
        sum += c - '0';
        if (c - '0' <= 3) {
            cnt[c - '0'] += 1;
        }
    }
    sum %= 9;

    if (sum == 0) {
        cout << "YES\n";
        return;
    }
    
    int need = 9 - sum;
    int cnt1 = cnt[2], cnt2 = cnt[3];
    if (need & 1) {
        need = (need + 9) / 2;
    } else {
        need /= 2;
    }
    while (need >= 0) {
        if (cnt1 >= need) {
            cout << "YES\n";
            return;
        }
        if (cnt2) {
            need -= 3, cnt2 -= 1;
        } else {
            break;
        }
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