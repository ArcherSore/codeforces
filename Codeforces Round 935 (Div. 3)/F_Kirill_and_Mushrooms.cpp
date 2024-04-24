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
    int n;
    cin >> n;
    vector<LL> exilr(n + 1), p(n + 1);
    set<LL, greater<LL>> s;
    map<LL, LL> num;
    for (int i = 1; i <= n; i++) {
        cin >> exilr[i];
        s.insert(exilr[i]);
        num[exilr[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    LL res = 0, cnt;
    for (int i = 1; i <= (n + 1) / 2; i++) {
        if (i * (*s.begin()) > res) {
            res = i * (*s.begin());
            cnt = i;
        }
        num[*s.begin()]--;
        if (num[*s.begin()] == 0) {
            s.erase(s.begin());
        }
        if (num[exilr[p[i]]] > 0) {
            num[exilr[p[i]]]--;
            if (num[exilr[p[i]]] == 0) {
                s.erase(exilr[p[i]]);
            }
        } else {
            num[*s.begin()]--;
            if (num[*s.begin()] == 0) {
                s.erase(s.begin());
            }
        }
    }
    cout << res << " " << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // freopen("input.in", "r", stdin);
    // freopen("main.out", "w", stdout);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}

/*
5
4 2 10 6 10
1 2 3  4 5     

1.
s = {10, 10, 6, 4, 2} -> 1 * 10 = 10

2. 
s = {10, 10, 6, 4, 2} -> {10, 10, 6, 2} -> {10, 6, 2} -> 2 * 10 = 20

3.
s = {10, 6, 2} -> {10, 6} -> {6} -> 3 * 6 = 18
*/