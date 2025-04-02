#include <bits/stdc++.h>
using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    int i;
    for (i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            break;
        }
    }
    if (a[i] < b[i]) {
        swap(a, b);
    }
    for (int j = i + 1; j < a.size(); j++) {
        if (a[j] > b[j]) {
            swap(a[j], b[j]);
        }
    }

    cout << a << '\n' << b << '\n';
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