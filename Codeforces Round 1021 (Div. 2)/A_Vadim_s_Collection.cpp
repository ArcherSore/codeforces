#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (auto c : s) {
        cnt[c - '0']++;
    }
    for (int i = 0; i < s.size(); i++) {
        int nd = 10 - i - 1;
        for (int j = nd; j < 10; j++) {
            if (cnt[j]) {
                cout << j;
                cnt[j]--;
                break;
            }
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