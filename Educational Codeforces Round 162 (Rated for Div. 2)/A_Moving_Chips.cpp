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

typedef long long LL;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            l++;
        } else {
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            r--;
        } else {
            break;
        }
    }
    for (int i = l; i <= r; i++) {
        if (a[i] == 0) {
            ans++;
        }
    }
    cout << ans << '\n';
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