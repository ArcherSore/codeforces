#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

void solve() {
    string s;
    cin >> s;
    int n1 = 0, n2 = 0;
    for (auto c : s) {
        if (c == 'A') {
            n1++;
        } else {
            n2++;
        }
    }
    cout << (n1 > n2 ? "A\n" : "B\n"); 
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}