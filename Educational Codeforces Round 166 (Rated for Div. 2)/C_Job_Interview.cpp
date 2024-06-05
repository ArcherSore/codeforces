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
    const int N = n + m + 1;;
    vector<LL> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    set<int> s1, s2;
    int bad = -1, type; // 记录第一个被迫营业的位置和类型
    vector<LL> ans(N);
    for (int i = 0; i < N - 1; i++) {
        if (a[i] > b[i]) {
            if (s1.size() < n) {
                s1.insert(i);
                ans[N - 1] += a[i];
            } else {
                s2.insert(i);
                ans[N - 1] += b[i];
                if (bad == -1) {
                    bad = i;
                    type = 2;
                }
            }
        } else {
            if (s2.size() < m) {
                ans[N - 1] += b[i];
                s2.insert(i);
            } else {
                s1.insert(i);
                ans[N - 1] += a[i];
                if (bad == -1) {
                    bad = i;
                    type = 1;
                }
            }
        }
    }

    // 删第i个，加入最后一个
    for (int i = N - 2; i >= 0; i--) {
        if (s1.find(i) != s1.end()) {
            if (i >= bad) {
                ans[i] = ans[N - 1] - a[i] + a[N - 1];
            } else {
                if (type == 2) {
                    ans[i] = ans[N - 1] - a[i] - b[bad] + a[bad] + b[N - 1];
                } else {
                    ans[i] = ans[N - 1] - a[i] + a[N - 1];
                }
            }
        } else {
            if (i >= bad) {
                ans[i] = ans[N - 1] - b[i] + b[N - 1];
            } else {
                if (type == 1) {
                    ans[i] = ans[N - 1] - b[i] - a[bad] + b[bad] + a[N - 1];
                } else {
                    ans[i] = ans[N - 1] - b[i] + b[N - 1];
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " "; 
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