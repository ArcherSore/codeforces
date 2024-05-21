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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> dis(m);
    vector<char> dir(m);
    for (int i = 0; i < m; i++) {
        cin >> dis[i] >> dir[i];
    }

    set<int> pos[2];
    pos[1].insert(k - 1);
    for (int i = 0; i < m; i++) {
        for (auto x : pos[1 - i % 2]) {
            if (dir[i] == '0') {
                pos[i % 2].insert((x + dis[i]) % n);
            } else if (dir[i] == '1') {
                pos[i % 2].insert((x - dis[i] + n) % n);    
            } else {
                pos[i % 2].insert((x + dis[i]) % n);
                pos[i % 2].insert((x - dis[i] + n) % n);
            }
        }
        pos[1 - i % 2].clear();
    }
    cout << pos[(m - 1) % 2].size() << '\n';
    for (auto x : pos[(m - 1) % 2]) {
        cout << x + 1 << ' ';
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