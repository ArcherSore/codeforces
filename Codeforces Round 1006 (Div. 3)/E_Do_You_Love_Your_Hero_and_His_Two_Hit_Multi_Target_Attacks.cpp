#include <bits/stdc++.h>
using namespace std;

using LL = long long;

void solve() {
    int k;
    cin >> k;

    if (k == 0) {
        cout << 1 << "\n" << 0 << " " << 0 << "\n";
        return;
    }

    int m = -1;
    vector<int> extot;

    for (int i = 500; i >= 1; i--) {
        LL hor = 1LL * i * (i - 1) / 2;
        if (hor > k) {
            continue;;
        }
        LL rest = k - hor;
        int avai = 500 - i;

        auto find = [&](LL _rest) -> LL {
            LL k = 1;
            while (1) {
                if (k * (k + 1) / 2 > _rest) {
                    break;
                }
                k++;
            }
            return k - 1;
        };

        vector<int> extra;
        while (rest > 0) {
            LL num = find(rest);
            rest -= (1 + num) * num / 2;
            extra.push_back(num);
        }
        if (rest > 0 || extra.size() > i) {
            continue;
        }
        extot = extra;
        m = i;
    }
    int tot = m;
    for (auto x : extot) {
        tot += x;
    }
    cout << tot << '\n';
    for (int i = 0; i < m; i++) {
        cout << i << ' ' << 0 << '\n';
    }
    int st = 0, h = 1;
    for (auto x : extot) {
        for (int j = 1; j <= x; j++) {
            cout << st << ' ' << h << '\n';
            h++;
        }
        st++;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}