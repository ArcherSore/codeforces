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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> deck(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> deck[i][j];
        }
        sort(deck[i].begin(), deck[i].end());
    }

    vector<int> p(n);
    vector<PII> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(deck[i][0], i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        p[i] = v[i].second;
    }

    auto check = [&]() -> bool {
        int flag = false;
        int pre = -1;
        for (int j = 0; j < m; j++) {
            for (auto i : p) {
                if (deck[i][j] < pre) {
                    return false;
                }
                pre = deck[i][j];
            }
        }
        return true;
    };

    if (check()) {
        for (auto x : p) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
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