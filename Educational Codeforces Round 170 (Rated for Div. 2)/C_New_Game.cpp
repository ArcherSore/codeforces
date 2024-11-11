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
    int n, k;
    cin >> n >> k;
    map<int, int> v;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        v[x] += 1;
    }

    queue<int> q;
    int ans = 0, tmp;
    q.push((*v.begin()).second);
    auto pre = v.begin();
    
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it == v.begin()) {
            tmp = (*it).second;
            continue;
        }

        if ((*it).first == (*pre).first + 1) {
            if (q.size() == k) {
                ans = max(ans, tmp);
                tmp -= q.front();
                q.pop();
            }
            q.push((*it).second);
            tmp += (*it).second;
        } else {
            ans = max(ans, tmp);
            while (!q.empty()) {
                q.pop();
            }
            q.push((*it).second);
            tmp = (*it).second;
        }

        pre = it;
    }
    ans = max(ans, tmp);
    cout << ans << '\n';
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