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

int digit(string &s) {
    int sum = 0;
    for (auto c : s) {
        sum += (c - '0');
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    string s[n];
    map<pair<int, int>, int> st;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        int len = s[i].size(), sum = digit(s[i]);
        st[{len, sum}]++;
    }

    LL res = 0;
    for (int i = 0; i < n; i++) {
        int slen = s[i].size();
        int sum = digit(s[i]);
        for (int j = 0; j < slen; j++) {
            string t = s[i].substr(0, j);
            int sum1 = digit(t), sum2 = sum - sum1;
            // head
            res += st[{slen - 2 * j, sum2 - sum1}];
            // tail
            res += st[{2 * j - slen, sum1 - sum2}];
        }
    }
    cout << res << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}