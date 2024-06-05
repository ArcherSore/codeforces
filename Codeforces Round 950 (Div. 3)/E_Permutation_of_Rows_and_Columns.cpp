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
    vector<vector<int>> a(n, vector<int> (m));
    vector<vector<int>> b(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    map<int, set<int>> t;
    for (int i = 0; i < n; i++) {
        set<int> tmp;
        for (int j = 0; j < m; j++) {
            tmp.insert(a[i][j]);
        }
        t[*tmp.begin()] = tmp;
    }
    for (int i = 0; i < n; i++) {
        set<int> tmp;
        for (int j = 0; j < m; j++) {
            tmp.insert(b[i][j]);
        }
        if (t[*tmp.begin()] != tmp) {
            cout << "NO\n";
            return;
        }
    }

    t.clear();
    for (int j = 0; j < m; j++) {
        set<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.insert(a[i][j]);
        }
        t[*tmp.begin()] = tmp;
    }
    for (int j = 0; j < m; j++) {
        set<int> tmp;
        for (int i = 0; i < n; i++) {
            tmp.insert(b[i][j]);
        }
        if (t[*tmp.begin()] != tmp) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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