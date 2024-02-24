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

const int MASK = 2147483647;

void solve() {
    int n;
    cin >> n;
    map<int, int> number;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        number[x]++;
    }

    int res = 0;
    for (auto [x, num] : number) {
        if (number.find(x ^ MASK) != number.end()) {
            res += min(num, number[x ^ MASK]);
            number.erase(x ^ MASK);
        }
    }
    cout << n - res << '\n';
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