#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct State {
    char lop, rop;
    int lv, rv;
};

void solve() {
    int n;
    cin >> n;
    vector<State> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].lop >> v[i].lv >> v[i].rop >> v[i].rv;
    }
    
    LL sum = 0, avai = 0;
    LL le = 1, ri = 1;
    for (int i = 0; i < n; i++) {
        if (v[i].lop == '+' && v[i].rop == '+') {
            avai += v[i].lv + v[i].rv;
        } else if (v[i].lop == 'x' && v[i].rop == 'x') {
            if (v[i].lv == v[i].rv) {
                avai += (v[i].lv - 1) * (le + ri + avai);
            } else {
                if (v[i].lv == 3) {
                    le += avai;
                    avai = ri + 2 * le;
                } else {
                    ri += avai;
                    avai = 2 * ri + le;
                }
            }
        } else {
            if (v[i].lop == 'x') {
                le += avai;
                avai = (v[i].lv - 1) * le + v[i].rv;
            } else {
                ri += avai;
                avai = (v[i].rv - 1) * ri + v[i].lv;
            }
        }
    }

    cout << le + ri + avai << '\n';
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