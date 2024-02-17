#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>
#include <set> 
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int num = a.size(), res = 0;
    int l = 0, r = 0;
    while (r != num) {
        if (a[r] - a[l] < n) {
            res = max(res, r - l + 1);
            r++;
        } else {
            l++;
        }

        if (l == r) {
            r += 1;
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