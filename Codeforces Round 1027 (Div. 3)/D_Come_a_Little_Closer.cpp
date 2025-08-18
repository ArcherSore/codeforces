#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const LL INF = 1e18;

void solve() {
    int n;
    cin >> n;

    LL x1 = INF, y1 = INF, x2 = 0, y2 = 0;
    vector<pair<LL, LL>> v(n);
    for (auto &p : v) {
        cin >> p.first >> p.second;
        x1 = min(x1, p.first);
        y1 = min(y1, p.second);
        x2 = max(x2, p.first);
        y2 = max(y2, p.second);
    }
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }

    LL area = (x2 - x1 + 1) * (y2 - y1 + 1);
    LL res = area;

    int cnt_left = 0, cnt_right = 0, cnt_bottom = 0, cnt_top = 0;
    for (auto &p : v) {
        if (p.first == x1) cnt_left++;
        if (p.first == x2) cnt_right++;
        if (p.second == y1) cnt_bottom++;
        if (p.second == y2) cnt_top++;
    }

    LL sec_x1 = INF, sec_y1 = INF;
    LL sec_x2 = 0, sec_y2 = 0;
    for (auto &p : v) {
        if (p.first > x1) {
            sec_x1 = min(sec_x1, p.first);
        }
        if (p.first < x2) {
            sec_x2 = max(sec_x2, p.first);
        }
        if (p.second > y1) {
            sec_y1 = min(sec_y1, p.second);
        }
        if (p.second < y2) {
            sec_y2 = max(sec_y2, p.second);
        }
    }

    for (auto &p : v) {
        bool good = false;
        LL new_x1 = x1, new_x2 = x2, new_y1 = y1, new_y2 = y2;
        if (p.first == x1 && cnt_left == 1 && sec_x1 != INF) {
            new_x1 = sec_x1;
            good = true;
        }
        if (p.first == x2 && cnt_right == 1 && sec_x2 != 0) {
            new_x2 = sec_x2;
            good = true;
        }
        if (p.second == y1 && cnt_bottom == 1 && sec_y1 != INF) {
            new_y1 = sec_y1;
            good = true;
        }
        if (p.second == y2 && cnt_top == 1 && sec_y2 != 0) {
            new_y2 = sec_y2;
            good = true;
        }
        if (!good) {
            continue;
        }
        LL tmp = (new_x2 - new_x1 + 1) * (new_y2 - new_y1 + 1);
        if (tmp == (LL)n - 1) {
            tmp += min(new_x2 - new_x1 + 1, new_y2 - new_y1 + 1);
        }
        res = min(res, tmp);
    }

    cout << res << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;

    while(T--) {
        solve();
    }

    return 0;
}