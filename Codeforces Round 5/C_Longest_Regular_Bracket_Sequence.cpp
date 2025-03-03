#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    stack<int> st;
    int n = s.size();
    vector<int> vis(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        if (s[i] == ')' && !st.empty()) {
            vis[st.top()] = 1;
            st.pop();
            vis[i] = 1;
        }
    }
    map<int, int> cnt;
    int len = vis[0];
    for (int i = 1; i < n; i++) {
        if (vis[i]) {
            len++;
        } else {
            cnt[len]++;
            len = 0;
        }
    }
    cnt[len]++;
    int mx = (*cnt.rbegin()).first;
    int re = (*cnt.rbegin()).second;
    if (mx == 0) {
        cout << 0 << ' ' << 1 << '\n';
    } else {
        cout << mx << ' ' << re;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}