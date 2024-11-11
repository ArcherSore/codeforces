// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    map<int, int> mp;
    vector<set<int>> pos(n);

    vector<int> a(n);
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        mp[x] = i;
        a[i] = mp[x];
    }
    vector<int> b(m);
    for (int i = 0, x; i < m; i++) {
        cin >> x;
        b[i] = mp[x];
        pos[mp[x]].insert(i);
    }

    vector<int> fir(n, m);
    for (int i = 0; i < m; i++) {
        fir[b[i]] = pos[b[i]].empty() ? m : *pos[b[i]].begin();
    }

    int num = 0;
    for (int i = 1; i < n; i++) {
        if (fir[i] >= fir[i - 1]) {
            num += 1;
        }
    }
    if (num == n - 1) {
        cout << "YA\n";
    } else {
        cout << "TIDAK\n";
    }

    while (q--) {
        int t, x;
        cin >> t >> x;
        t -= 1, x = mp[x];

        // update fir array
        int pre = b[t], cur_fir;
        pos[pre].erase(t);
        cur_fir = pos[pre].empty() ? m : *pos[pre].begin();
        // calculate the impact of pre
        if (pre != n - 1) {
            if (fir[pre] <= fir[pre + 1] && cur_fir > fir[pre + 1]) {
                num -= 1;
            }
            if (fir[pre] > fir[pre + 1] && cur_fir <= fir[pre + 1]) {
                num += 1;
            }
        }
        if (pre != 0) {
            if (fir[pre - 1] <= fir[pre] && fir[pre - 1] > cur_fir) {
                num -= 1;
            }
            if (fir[pre - 1] > fir[pre] && fir[pre - 1] <= cur_fir) {
                num += 1;
            }
        }
        fir[pre] = cur_fir;

        b[t] = x;
        pos[x].insert(t);
        cur_fir = pos[x].empty() ? m : *pos[x].begin();
        // calculate the impact of cur
        if (x != n - 1) {
            if (fir[x] <= fir[x + 1] && cur_fir > fir[x + 1]) {
                num -= 1;
            }
            if (fir[x] > fir[x + 1] && cur_fir <= fir[x + 1]) {
                num += 1;
            }
        }
        if (x != 0) {
            if (fir[x - 1] <= fir[x] && fir[x - 1] > cur_fir) {
                num -= 1;
            }
            if (fir[x - 1] > fir[x] && fir[x - 1] <= cur_fir) {
                num += 1;
            }
        }
        fir[x] = cur_fir;

        if (num == n - 1) {
            cout << "YA\n";
        } else {
            cout << "TIDAK\n";
        }
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