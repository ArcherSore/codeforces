#include <iostream>
#include <map>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    map<char, int> ind;
    char c;
    for (int i = 0; i < n; i++) {
        cin >> c;
        ind[c]++;
    }
    int cnt = 0;
    for (auto x : ind) {
        if (x.second % 2) {
            cnt++;
        }
    }
    // cout << cnt << " " << k << endl;
    if (k >= cnt - 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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