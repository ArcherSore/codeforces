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

struct Enemy{
    int health, pos;
};

bool cmp(Enemy &a, Enemy &b) {
    if (abs(a.pos) != abs(b.pos)) {
        return abs(a.pos) < abs(b.pos);
    }
    return a.health < b.health;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<Enemy> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].health;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].pos;
    }
    sort(arr.begin(), arr.end(), cmp);
    LL need = 0;
    for (auto e : arr) {
        need += e.health;
        if (1LL * abs(e.pos) * k < need) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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