#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n, m;
    cin >> n;
    m = n - 2;
    vector<int> v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    
    int flag = 1;
    if (m >= 3) {
        for (int i = 0; i + 2 < m; i++){
            if (v[i] == 1 && v[i + 1] == 0 && v[i + 2] == 1){
                flag = false;
                break;
            }
        }
    }
    
    cout << (flag? "YES" : "NO") << "\n";
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