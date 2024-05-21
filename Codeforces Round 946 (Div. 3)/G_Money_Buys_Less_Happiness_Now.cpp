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
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    priority_queue<int> h;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (s >= c[i]) {
            s -= c[i];
            h.push(c[i]);
        } else {
            if (!h.empty() && h.top() > c[i]) {
                s = s + h.top() - c[i];
                h.pop();
                h.push(c[i]);
            }
        }
        s += x;
    }
    cout << (int)h.size() << '\n';
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