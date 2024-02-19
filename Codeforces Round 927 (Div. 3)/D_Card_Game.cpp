#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

int mp[30];
char kk[4] = {'C', 'D', 'H', 'S'};

void init() {
    mp['C'] = 0, mp['D'] = 1, mp['H'] = 2, mp['S'] = 3;
}

void solve() {
    init();
    int n;
    cin >> n;
    char tru;
    cin >> tru;
    set<int> card[4];
    string ans[2 * n];
    for (int i = 0; i < 2 * n; i++) {
        string s;
        cin >> s;
        card[mp[s[1]]].insert(s[0] - '0');
    }

    int rr = 0;
    for (int i = 0; i < 4; i++) {
        if (i != mp[tru]) {
            while (card[i].size() > 1) {
                ans[2 * rr] = to_string(*(card[i].begin())) + kk[i];
                card[i].erase(card[i].begin());
                ans[2 * rr + 1] = to_string(*(card[i].begin())) + kk[i];
                card[i].erase(card[i].begin());

                rr++;
            }
            if (card[i].size() == 1) {
                ans[2 * rr] = to_string(*(card[i].begin())) + kk[i];
                card[i].erase(card[i].begin());
                if (card[mp[tru]].empty()) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                ans[2 * rr + 1] = to_string(*(card[mp[tru]].begin())) + tru;
                card[mp[tru]].erase(card[mp[tru]].begin());
                
                rr++;
            }
        }
    }

    while (!card[mp[tru]].empty()) {
        ans[2 * rr] = to_string(*(card[mp[tru]].begin())) + tru;
        card[mp[tru]].erase(card[mp[tru]].begin());
        ans[2 * rr + 1] = to_string(*(card[mp[tru]].begin())) + tru;
        card[mp[tru]].erase(card[mp[tru]].begin());

        rr++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[2 * i] << " " << ans[2 * i + 1] << '\n';
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}