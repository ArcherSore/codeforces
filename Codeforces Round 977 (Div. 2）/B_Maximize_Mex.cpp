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
    int n, t;
    cin >> n >> t;
    map<int, int> v;
    map<int, map<int, int>> r;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x] += 1;
        r[x % t][x] += 1;
    }
    for (int i = 0; i <= n; i++) {
        if (v.find(i) != v.end()) {
            v[i] -= 1;
            if (v[i] == 0) {
                v.erase(i);
            }
            r[i % t][i] -= 1;
            if (r[i % t][i] == 0) {
                r[i % t].erase(i);
                if (r[i % t].empty()) {
                    r.erase(i % t);
                }
            }
        } else {
            if (r.find(i % t) != r.end()) {
                int fir = (*r[i % t].begin()).first;
                if (fir < i) {
                    r[i % t][fir] -= 1;
                    if (r[i % t][fir] == 0) {
                        r[i % t].erase(fir);
                            if (r[i % t].empty()) {
                        r.erase(i % t);
                    }
                    }
                    v[fir] -= 1;
                    if (v[fir] == 0) {
                        v.erase(fir);
                    }
                } else {
                    cout << i << '\n';
                    return;
                }
            } else {
                cout << i << '\n';
                return;
            }
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