#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'a'] += 1;
    }
    int mx = 0, mn = n;
    char c, cc;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > mx) {
            mx = cnt[i];
            c = 'a' + i;
        }
        if (cnt[i] && cnt[i] <= mn) {
            mn = cnt[i];
            cc = 'a' + i;
        }
    }

    if (mn == n) {
        cc = c;
    }

    for (auto &tc : s) {
        if (tc == cc) {
            tc = c;
            break;
        }
    }
    cout << s << '\n';
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