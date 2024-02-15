#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int zeros = 0, ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
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