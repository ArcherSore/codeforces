#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    char c;
    int y;
    cin >> c >> y;
    for (int i = 1; i <= 8; i++) {
        if (i != y) {
            cout << c << i << '\n';
        }
    }
    for (int i = 1; i <= 8; i++) {
        if (c - 'a' + 1 != i) {
            cout << char(i + 'a' - 1) << y << '\n';
        }
    }

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}