// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

string ss[2] = {"AM", "PM"};

void solve() {
    string s;
    cin >> s;
    int h = (s[0] - '0') * 10 + (s[1] - '0');
    int m = (s[3] - '0') * 10 + (s[4] - '0');

    if (h < 12) {
        if (h == 0) {
            s[0] = '1', s[1] = '2';
        }
        cout << s << " " << ss[0] << '\n';
    }  else {
        h = h % 12;
        if (h == 0) {
            h = 12;
        }
        if (h < 10) {
            cout << 0;
        }
        cout << h << ":" << s[3] << s[4] << " " << ss[1] << '\n';
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