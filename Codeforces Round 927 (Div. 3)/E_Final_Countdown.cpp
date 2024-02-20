#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <cstring>
#include <map>
using namespace std;

typedef long long LL;

const int MAXN = 4e5 + 10;
int sum[MAXN];

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + s[i] - '0';
    }
    reverse(sum + 1, sum + n + 1);

    int k = 1;
    while (1) {
        sum[k + 1] += sum[k] / 10;
        sum[k] = sum[k] % 10;

        if (sum[k + 1] == 0) {
            break;
        }
        k++;
    }

    for (int i = k; i; i--) {
        cout << sum[i];
        sum[i] = 0;
    }
    cout << '\n';
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