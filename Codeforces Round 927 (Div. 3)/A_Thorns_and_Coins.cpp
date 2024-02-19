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
    string s;
    cin >> s;
    LL res = 0, th = 0;
    for (char c : s) {
        if (c == '*') {
            th++;
            if (th == 2) {
                cout << res << '\n';
                return;
            }
        } else {
            th = 0;
        }

        if (c == '@') {
            res++;
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