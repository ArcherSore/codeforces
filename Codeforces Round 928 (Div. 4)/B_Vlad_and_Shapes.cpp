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
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> front;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '1') {
                front.push_back(j);
                break;
            }
        }
    }

    int pre = front[0];
    for (int x : front) {
        if (x != pre) {
            cout << "TRIANGLE\n";
            return;
        }
        pre = x;
    }
    cout << "SQUARE\n";
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