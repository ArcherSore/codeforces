#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    vector<vector<int>> inv(n, vector<int>(n, 0));
    vector<vector<int>> niv(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++) {
        if (i + 1 < n) {
            inv[i][i+1] = (v[i] > v[i+1]) ? 1 : 0;
            niv[i][i+1] = (v[i] < v[i+1]) ? 1 : 0;
        }
        for (int j = i + 2; j < n; j++) {
            inv[i][j] = inv[i][j-1] + ((v[i] > v[j]) ? 1 : 0);
            niv[i][j] = niv[i][j-1] + ((v[i] < v[j]) ? 1 : 0);
        }
    }
    
    int cnt = -1e9;
    int bl, br;
    for (int l = 0; l < n; l++){
        for (int r = l; r < n; r++){
            if (inv[l][r] - niv[l][r] > cnt) {
                cnt = inv[l][r] - niv[l][r];
                bl = l + 1, br = r + 1;
            }
        }
    }
    cout << bl << ' ' << br << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}