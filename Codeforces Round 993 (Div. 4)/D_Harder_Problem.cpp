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
    int n;
    cin >> n;
    vector<int> v(n), vis(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vis[v[i]] = 1;
    }
    queue<int> avai;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            avai.push(i);
        }
    }

    vector<int> res(n);
    vis.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (!vis[v[i]]) {
            res[i] = v[i];
            vis[v[i]] = 1;
        } else {
            res[i] = avai.front();
            avai.pop();
        }
    }

    for (auto &x : res) {
        cout << x << ' ';
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