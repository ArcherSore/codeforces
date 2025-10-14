#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using ll = long long;

const int N = 2e5 + 10;
int trie[N][26];
ll cnt[N];
int tot = 2;

void insert(const string &s) {
    int p = 1;
    cnt[p]++;
    for (auto c : s) {
        if (trie[p][c - 'a'] == 0) {
            trie[p][c - 'a'] = ++tot;
        }
        p = trie[p][c - 'a'];
        cnt[p]++;
    }
}

ll res = 0;
void dfs(int u, int dep) {
    res += (cnt[u] / 2) * (cnt[u] - cnt[u] / 2);
    for (int i = 0; i < 26; i++) {
        if (trie[u][i] == 0) {
            continue;
        }
        dfs(trie[u][i], dep + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
    for (int i = 0; i < 26; i++) {
        if (trie[1][i] != 0) {
            dfs(trie[1][i], 1);
        }
    }
    cout << res << '\n';
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

// 3:39:13 2