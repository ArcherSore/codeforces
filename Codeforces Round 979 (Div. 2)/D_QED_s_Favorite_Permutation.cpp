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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
    }
    vector<int> mx(n);
    mx[0] = v[0];
    for (int i = 1; i < n; i++) {
        mx[i] = max(mx[i - 1], v[i]);
    }
    string s;
    cin >> s;
    set<int> p;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'L' && s[i + 1] == 'R' && mx[i] > i) {
            p.insert(i);
        }
    }

    while (q--) {
        int x;
        cin >> x;
        x--;
        if (s[x] == 'R') {
            s[x] = 'L';
        } else {
            s[x] = 'R';
        }

        if (s[x] == 'L') {
            if (s[x + 1] == 'R' && mx[x] > x) {
                p.insert(x);
            }
            if (s[x - 1] == 'L') {
                p.erase(x - 1);
            }
        } else {
            if (s[x + 1] == 'R') {
                p.erase(x);
            }
            if (s[x - 1] == 'L' && mx[x - 1] > x - 1) {
                p.insert(x - 1);
            }
        }
        if (p.size() == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
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