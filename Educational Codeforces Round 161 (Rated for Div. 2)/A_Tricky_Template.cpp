#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <numeric>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    int n;
    cin >> n;
    string a, b, c;
    cin >> a >> b >> c;
    for (int i = 0; i < n; i++) {
        if (a[i] != c[i] && b[i] != c[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}