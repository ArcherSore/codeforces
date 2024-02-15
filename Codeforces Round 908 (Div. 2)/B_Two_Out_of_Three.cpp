#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> num;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        num[a[i]]++;
    }
    int cnt = 0;
    int fis, sec;
    for (auto x : num) {
        if (x.second > 1) {
            if (cnt == 0) fis = x.first;
            if (cnt == 1) sec = x.first;
            cnt++;
        }
    }
    if (cnt < 2) {
        cout << "-1" << endl;
        return;
    }
    int flag1 = 0, flag2 = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == fis) {
            if (!flag1) cout << 1 << " ", flag1 = 1;
            else cout << 2 << " ";
        }
        else if (a[i] == sec) {
            if (!flag2) cout << 1 << " ", flag2 = 1;
            else cout << 3 << " ";
        }
        else {
            cout << 1 << " ";
        }
    }
    cout << "\n";
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}