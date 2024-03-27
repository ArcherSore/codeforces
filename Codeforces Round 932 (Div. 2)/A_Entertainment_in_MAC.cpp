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
    int n, len;
    cin >> n;
    string s;
    cin >> s;
    len = s.size();
    char a, b;
    for (int i = 0; i <= len / 2; i++) {
        a = s[i], b = s[len - i - 1];
        if (a != b) {
            break;
        }
    }

    if (a < b) {
        if (n % 2 == 0) {
            cout << s << '\n';
        } else {
            string t = s;
            reverse(t.begin(), t.end());
            s += t;
            cout << s << '\n';
        }
    } else if (a > b) {
        if (n % 2) {
            cout << s << '\n';
        } else {
            string t = s;
            reverse(t.begin(), t.end());
            t += s;
            cout << t << '\n';
        }
    } else {
        cout << s << '\n';
    }

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