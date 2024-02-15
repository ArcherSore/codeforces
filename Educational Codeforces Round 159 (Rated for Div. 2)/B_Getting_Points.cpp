#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

bool ok(LL n, LL P, LL x, LL y, LL k) {
    // 最后k天学习
    LL num = (n - 1) / 7 + 1; // 解锁的task
    if (num % 2) {
        // 奇数
        if (2 * k <= num) {
            return (2 * k * y + k * x) >= P;
        } else {
            return (num * y + k * x) >= P;
        }
    } else {
        // 偶数
        return (min(num / 2, k) * 2 * y + k * x) >= P;
    }
}

void solve() {
    LL n, P, x, y;
    cin >> n >> P >> x >> y;

    LL l = 0, r = n, mid; // mid学习天数
    while (l < r) {
        mid = (l + r) / 2;
        if (ok(n, P, x, y, mid)) r = mid;
        else l = mid + 1;
    }
    cout << n - l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}