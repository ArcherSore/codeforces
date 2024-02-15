#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int mx = 0;
    vector<int> a(260);
    for (int i = 0; i < n; i++) {
        a[s[i]]++;
        mx = max(mx, a[s[i]]);
    }
    if (mx > n / 2) {
        cout << mx - (n - mx) << '\n';
    } else {
        cout << n % 2 << '\n';
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}