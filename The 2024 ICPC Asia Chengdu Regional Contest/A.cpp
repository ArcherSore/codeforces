#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> st, ed;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            continue;
        }
        st.push_back(i);
        while (i < n && s[i] == '>') {
            i++;
        }
        i--;
        ed.push_back(i);
    }
    // '>'段少于2 or 首or尾不是'>' or 尾段长度<3
    if (st.size() < 2 || st[0] != 0 || ed.back() != n - 1 || ed.back() - st.back() + 1 < 3) {
        cout << "No\n";
        return;
    }

    int m = st.size();
    vector<pii> res; 
    for (int i = 0; i < m - 1; i++) {
        for (int j = st[i]; j <= ed[i]; j++) {
            int len = n - j;
            res.push_back({j + 1, len});
        }
    }
    for (int j = ed.back(); j >= st.back() + 2; j--) {
        int len = j - ed[m - 2] + 1;
        res.push_back({ed[m - 2] + 1, len});
    }
    cout << "Yes " << res.size() << '\n';
    for (auto [l, r] : res) {
        cout << l << ' ' << r << '\n';
    }
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