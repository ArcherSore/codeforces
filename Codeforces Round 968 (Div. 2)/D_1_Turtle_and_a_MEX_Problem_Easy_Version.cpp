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
    LL n, m;
    cin >> n >> m;

    map<LL, LL> f;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        vector<LL> v(cnt);
        for (int j = 0; j < cnt; j++) {
            cin >> v[j];
        }
        sort(v.begin(), v.end());

        v.erase(unique(v.begin(), v.end()), v.end());
        cnt = v.size();

        LL fir = -1, sec = -1;
        if (v[0] > 1) {
            fir = 0, sec = 1;
        } else if (v[0] == 1) {
            fir = 0;
            for (int j = 1; j < cnt; j++) {
                if (v[j] > v[j - 1] + 1) {
                    sec = v[j - 1] + 1;
                    break;
                }
            }
            if (sec == -1) {
                sec = v.back() + 1;
            }
        } else {
            for (int j = 1; j < cnt;  j++) {
                if (v[j] == v[j - 1] + 2) {
                    if (fir == -1) {
                        fir = v[j - 1] + 1;
                    } else {
                        sec = v[j - 1] + 1;
                        break;
                    }
                } else if (v[j] > v[j - 1] + 2) {
                    if (fir == -1) {
                        fir = v[j - 1] + 1;
                        sec = fir + 1;
                        break;
                    } else {
                        sec = v[j - 1] + 1;
                        break;
                    }
                }
            }
            if (fir == -1) {
                fir = v.back() + 1;
                sec = fir + 1;
            } else if (sec == -1) {
                sec = v.back() + 1;
            }
        }

        if (f.find(fir) != f.end()) {
            f[fir] = max(f[fir], sec);
        } else {
            f[fir] = sec;
        }
    }

    LL sec = 0;
    for (auto [x, y] : f) {
        sec = max(sec, y);
    }
 
    LL ans = m * (m + 1) / 2;
    if (m >= sec) {
        ans = ans - (sec - 1) * sec / 2 + sec * sec;
    } else {
        ans = ans - m * (m + 1) / 2 + sec * (m + 1);
    }
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
