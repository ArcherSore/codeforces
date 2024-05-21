// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#include <numeric>
#include <stack>
#include <set>
#include <map>

using namespace std;

using LL = long long;
using PII = pair<int, int>;

struct Pos {
    LL x, y, z;
    bool operator<(const Pos &other) const {
        if (x != other.x) {
            return x < other.x;
        } else if (y != other.y) {
            return y < other.y;
        } else {
            return z < other.z;
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<LL> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<Pos, LL> num1, num2, num3;
    for (int i = 2; i < n; i++) {
        num1[{a[i - 2], a[i - 1], a[i]}]++;
        num2[{a[i - 1], a[i], a[i - 2]}]++;
        num3[{a[i], a[i - 2], a[i - 1]}]++;
    }
    LL l_x = 0, l_y = 0, l_z = 0, l_num = 0;
    LL res = 0;
    for (auto [x, num] : num1) {
        if (l_x == 0 && l_y == 0 && l_z == 0) {
            l_x = x.x, l_y = x.y, l_z = x.z;
            l_num = num;
        } else {
            if (x.x == l_x && x.y == l_y) {
                res += 1LL * l_num * num;
                l_num += num;
            } else {
                l_x = x.x, l_y = x.y, l_z = x.z;
                l_num = num;
            }
        }
    }
    l_x = 0, l_y = 0, l_z = 0;
    for (auto [x, num] : num2) {
        if (l_x == 0 && l_y == 0 && l_z == 0) {
            l_x = x.x, l_y = x.y, l_z = x.z;
            l_num = num;
        } else {
            if (x.x == l_x && x.y == l_y) {
                res += 1LL * l_num * num;
                l_num += num;
            } else {
                l_x = x.x, l_y = x.y, l_z = x.z;
                l_num = num;
            }
        }
    }
    l_x = 0, l_y = 0, l_z = 0;
    for (auto [x, num] : num3) {
        if (l_x == 0 && l_y == 0 && l_z == 0) {
            l_x = x.x, l_y = x.y, l_z = x.z;
            l_num = num;
        } else {
            if (x.x == l_x && x.y == l_y) {
                res += 1LL * l_num * num;
                l_num += num;
            } else {
                l_x = x.x, l_y = x.y, l_z = x.z;
                l_num = num;
            }
        }
    }
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