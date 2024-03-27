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
    vector<int> a(n + 1);
    vector<int> cnt1(n + 1), cnt2(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt2[a[i]]++;
    }
    int mex1 = 0, mex2 = 0;
    while (cnt2[mex2]) {
        mex2++;
    }

    for (int i = 1; i <= n; i++) {
        cnt1[a[i]]++;
        while (cnt1[mex1]) {
            mex1++;
        }

        cnt2[a[i]]--;
        if (cnt2[a[i]] == 0 && a[i] < mex2) {
            mex2 = a[i];
        }
        // cout << mex1 << " " << mex2 << '\n';
        if (mex1 == mex2) {
            cout << 2 << '\n' << 1 << " " << i << '\n' << i + 1 << " " << n << '\n';
            return;
        }
    }
    cout << -1 << '\n';
    return;
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