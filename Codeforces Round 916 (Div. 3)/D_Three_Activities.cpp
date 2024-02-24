#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <numeric>
#include <set> 
#include <stack> 
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    vector<int> ind_a(n), ind_b(n), ind_c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind_a[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        ind_b[i] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        ind_c[i] = i;
    }
    sort(ind_a.begin(), ind_a.end(), [&](int i, int j) -> bool {
        return a[i] > a[j];
    });
    sort(ind_b.begin(), ind_b.end(), [&](int i, int j) -> bool {
        return b[i] > b[j];
    });
    sort(ind_c.begin(), ind_c.end(), [&](int i, int j) -> bool {
        return c[i] > c[j];
    });

    int res = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (ind_a[i] != ind_b[j] && ind_b[j] != ind_c[k] && ind_c[k] != ind_a[i]) {
                    res = max(res, a[ind_a[i]] + b[ind_b[j]] + c[ind_c[k]]);
                }
            }
        }
    }
    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}