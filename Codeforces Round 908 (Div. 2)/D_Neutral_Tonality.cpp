#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end(), greater<int> ());

    int p = 0, q = 0;
    while (p < n && q < m) {
        if (b[q] >= a[p]) {
            cout << b[q] << " ";
            q++;
        } else {
            cout << a[p] << " ";
            p++;
        }
    }
    for (int i = p; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = q; i < m; i++) {
        cout << b[i] << " ";
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