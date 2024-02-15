#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int last = b[n], ind = n;
    for (int i = 1; i <= min(n, k); i++) {
        if (last > n) {
            cout << "No\n";
            return;
        }
        ind -= last;
        if (ind <= 0) ind += n;
        last = b[ind];
        // cout << "ind = " << ind << ", last = " << last << "\n";
    }
    cout << "Yes\n";
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