#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

void solve() {
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    
    int res = 0;
    auto count = [&](int x) -> int {
        int zero_cnt = 0;
        if (x == 0) {
            zero_cnt = 30;
        } else {
            while (((x >> zero_cnt) & 1) == 0) {
                zero_cnt++;
            }
        }
        return zero_cnt;
    };
    auto work = [&](auto &self, int x1, int x2, int y1, int y2) -> void {
        if (x1 >= x2 || y1 >= y2) {
            return;
        }

        if (x2 - x1 > y2 - y1) {
            self(self, y1, y2, x1, x2);
            return;
        }

        for (int x = x1; x < x2; ) {
            int zero_cnt = count(x);
            while (x + (1 << zero_cnt) > x2 && zero_cnt > 0) {
                zero_cnt--;
            }
            int offset = (1 << zero_cnt);
            
            int ty1 = y1 >> zero_cnt << zero_cnt;
            int ty2 = y2 >> zero_cnt << zero_cnt;
            while (ty1 < y1) {
                ty1 += offset;
            }
            if (ty2 >= ty1) {
                res += (ty2 - ty1) / offset;
            }
            self(self, x, x + offset, y1, ty1);
            self(self, x, x + offset, ty2, y2);

            x += offset;
        }
    };
    work(work, l1, r1, l2, r2);
    cout << res << '\n';
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