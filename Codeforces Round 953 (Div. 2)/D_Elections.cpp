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
    LL n, c;
    cin >> n >> c;
    vector<LL> a(n);
    map<LL, int, greater<LL>> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            a[i] += c;
        }
        mp[a[i]]++;
    }

    LL mx = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        // 判断i之前的最大值是否大于ai
        if (a[i] <= mx) {
            cnt += i;
            // a[i]->a[i]+sum
            auto it = mp.begin();
            if ((*it).first > a[i] + sum) {
                cnt += 1;
            }
        } else {
            auto it = mp.begin();
            if ((*it).first > a[i] + sum) {
                cnt += i + 1;
            } else if ((*it).first > a[i]) {
                cnt += i;
            }
        }
        // 更新变量
        mx = max(mx, a[i]);
        sum += a[i];
        mp[a[i]]--;
        if (mp[a[i]] == 0) {
            mp.erase(a[i]);
        }

        cout << cnt << ' ';
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