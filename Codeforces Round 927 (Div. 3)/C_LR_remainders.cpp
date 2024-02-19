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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<char> opt(n);
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        cin >> opt[i];
        if (i) {
            if (opt[i] == 'L') {
                l++;
            } else {
                r--;
            }
        }
    }

    // cout << "l = " << l << '\n';
    LL mod = a[l] % m;
    vector<int> ans(n);
    ans[0] = mod;
    for (int i = 1; i < n; i++) {
        if (opt[i] == 'L') {
            l -= 1;
            mod = (mod * a[l]) % m;
            ans[i] = mod;
        } else {
            r += 1;
            mod = (mod * a[r]) % m;
            ans[i] = mod;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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