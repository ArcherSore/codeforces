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

void solve() {
    int n;
    cin >> n;
    string s, tmp;
    // 向左
    while (1) {
        if (n == s.size()) {
            break;
        }
        int opt;

        tmp = "1" + s;
        cout << "? " << tmp << endl;
        cin >> opt;
        if (opt == 1) {
            s = tmp;
            continue;
        }

        tmp = "0" + s;
        cout << "? " << tmp << endl;
        cin >> opt;
        if (opt == 1) {
            s = tmp;
            continue;
        }
        break;
    }
    // 向右
    while (1) {
        if (n == s.size()) {
            break;
        }

        int opt;

        tmp = s + "1";
        cout << "? " << tmp << endl;
        cin >> opt;
        if (opt == 1) {
            s = tmp;
        } else {
            s = s + "0";
        }
    }

    cout << "! " << s << endl;
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