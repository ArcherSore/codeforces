#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n <= k) {
        for (char i = 'a'; i < 'a' + n; i++) {
            cout << i;
            for (char j = 'a'; j < 'a' + k; j++) {
                if (j == i) continue;
                cout << j;
            }
        }
        cout << '\n';
    } else {
        // 
        for (int i = 0; i < n; i++) {
            for (char j = 'a'; j < 'a' + k; j++) {
                cout << j;
            }
        }
        cout << '\n';
    }
    
    return;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}