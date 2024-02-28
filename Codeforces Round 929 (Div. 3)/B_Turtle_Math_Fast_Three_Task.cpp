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

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> cnt(3);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x % 3]++;
        sum += x;
    }
    if (sum % 3 == 0) {
        cout << 0 << '\n';
    } else if (sum % 3 == 1) {
        if (cnt[1]) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    } else {
        if (cnt[1] || cnt[2]) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }

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