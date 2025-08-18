#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;

const int inf = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<vector<set<int>>> cnt(3, vector<set<int>> (3));
    for (int i = 0; i < q; i++) {
        char x, y;
        cin >> x >> y;
        cnt[x - 'a'][y - 'a'].insert(i);
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            continue;
        } else if (s[i] == 'b') {
            if (!cnt[1][0].empty()) {
                cnt[1][0].erase(cnt[1][0].begin());
                s[i] = 'a';
                continue;
            }
            if (!cnt[1][2].empty()) {
                auto j = *cnt[1][2].begin();
                auto it = cnt[2][0].lower_bound(j);
                if (it != cnt[2][0].end()) {
                    cnt[1][2].erase(j);
                    cnt[2][0].erase(it);
                    s[i] = 'a';
                    continue;
                }
            }
        } else {
            if (!cnt[2][0].empty()) {
                cnt[2][0].erase(cnt[2][0].begin());
                s[i] = 'a';
                continue;
            }
            if (!cnt[2][1].empty()) {
                auto j = *cnt[2][1].begin();
                cnt[2][1].erase(j);
                s[i] = 'b';
                auto it = cnt[1][0].lower_bound(j);
                if (it != cnt[1][0].end()) {
                    cnt[1][0].erase(it);
                    s[i] = 'a';
                    continue;
                }
            }
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