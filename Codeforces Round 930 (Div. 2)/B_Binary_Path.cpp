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

bool check(string &s, string &res, int mid, int p) {
    return s.substr(mid, p - mid + 1) == res.substr(mid + 1, p - mid + 1);
}

void solve() {
    int n;
    cin >> n;
    string s[2];
    cin >> s[0] >> s[1];
    string res;
    int x = 0, y = 0;
    int p;
    while (x != 1 || y != n - 1) {
        res += s[x][y];
        if (x == 1) {
            y += 1;
        } else {
            if (s[x][y + 1] == '1' && s[x + 1][y] == '0' || y == n - 1) {
                x += 1;
                p = y;
            } else {
                y += 1;
            }
        }
    }
    res += s[x][y];
    cout << res << '\n';

    int l = 0, r = p, mid;
    while (l < r) {
        mid = (l + r) / 2;
        if (check(s[1], res, mid, p)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << p - l + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}