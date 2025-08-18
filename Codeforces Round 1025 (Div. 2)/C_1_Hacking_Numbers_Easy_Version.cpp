#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, op;
    cin >> n;
    cout << "digit" << endl;
    cin >> op;
    cout << "mul 99" << endl;
    cin >> op;
    cout << "digit" << endl; // x = 18
    cin >> op;
    cout << "add " << n - 18 << endl;
    cin >> op;
    cout << "!" << endl;
    cin >> op;
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