#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

map<char, int> mp;
// L I T

char ins(char a, char b) {
    vector<int> vis(3);
    vis[mp[a]] = vis[mp[b]] = 1;
    if (!vis[0]) {
        return 'L';
    } else if (!vis[1]) {
        return 'I';
    } else {
        return 'T';
    }
}

int is_balanced(string &s) {
    vector<int> cnt(3);
    for (char c : s) {
        cnt[mp[c]]++;
    }
    return cnt[0] == cnt[1] && cnt[1] == cnt[2];
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (is_balanced(s)) {
        cout << 0 << '\n';
        return;
    }

    int flag = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[0]) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        cout << -1 << '\n';
        return;
    }

    vector<int> opt;
    while (!is_balanced(s) && opt.size() < 2 * n) {
        vector<int> cnt(3);
        for (char c : s) {
            cnt[mp[c]]++;
        }

        char need;
        // L I T
        if (cnt[0] <= cnt[1] && cnt[0] <= cnt[2]) {
            need = 'L';
        } else if (cnt[1] <= cnt[0] && cnt[1] <= cnt[2]) {
            need = 'I';
        } else {
            need = 'T';
        }

        int inserted = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1]) {
                char ch = ins(s[i], s[i + 1]);
                if (ch == need) {
                    s.insert(s.begin() + i + 1, ch);
                    opt.push_back(i + 1);
                    inserted = 1;
                    break;
                }
            }
        }

        if (!inserted) {
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] != s[i + 1]) {
                    char ch = ins(s[i], s[i + 1]);
                    s.insert(s.begin() + i + 1, ch);
                    opt.push_back(i + 1);
                    inserted = 1;
                    break;
                }
            }
        }

        if (!inserted) {
            break;
        }
    }

    if (!is_balanced(s)) {
        cout << -1 << '\n';
    } else {
        cout << opt.size() << '\n';
        for (auto x : opt) {
            cout << x << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    mp['L'] = 0;
    mp['I'] = 1;
    mp['T'] = 2;

    while (T--) {
        solve();
    }

    return 0;
}