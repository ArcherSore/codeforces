#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    
    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    vector<LL> suma(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        suma[i] = suma[i - 1] + a[i];
    }
    
    vector<LL> P(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        P[i] = P[i - 1] + suma[i];
    }
    
    vector<LL> complete(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        complete[i] = (P[n] - P[i - 1]) - 1LL * (n - i + 1) * suma[i - 1];
    }
    
    vector<LL> pre_com(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre_com[i] = pre_com[i - 1] + complete[i];
    }
    
    vector<LL> T(n + 1, 0);
    T[0] = 0;
    for (int i = 1; i <= n; i++) {
        T[i] = T[i - 1] + (n - i + 1);
    }
    
    auto getRowCol = [&](LL pos) -> PII {
        int row = lower_bound(T.begin(), T.end(), pos + 1) - T.begin();
        int offset = pos - T[row - 1];
        int col = row + offset;
        return make_pair(row, col);
    };
    
    int q;
    cin >> q;
    while (q--) {
        LL l, r;
        cin >> l >> r;
        l--, r--;
        
        PII leftRC  = getRowCol(l);
        PII rightRC = getRowCol(r);
        int i1 = leftRC.first, j1 = leftRC.second;
        int i2 = rightRC.first, j2 = rightRC.second;
        
        LL res = 0;
        if (i1 == i2) {
            res = (P[j2] - P[j1 - 1]) - 1LL * (j2 - j1 + 1) * suma[i1 - 1];
        } else {
            LL leftPart = (P[n] - P[j1 - 1]) - 1LL * (n - j1 + 1) * suma[i1 - 1];
            LL rightPart = (P[j2] - P[i2 - 1]) - 1LL * (j2 - i2 + 1) * suma[i2 - 1];
            LL midPart = 0;
            if (i2 > i1 + 1) {
                midPart = pre_com[i2 - 1] - pre_com[i1];
            }
            res = leftPart + midPart + rightPart;
        }
        cout << res << "\n";
    }
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;

    // cin >> T_case;
    
    while (T--) {
        solve();
    }
    
    return 0;
}