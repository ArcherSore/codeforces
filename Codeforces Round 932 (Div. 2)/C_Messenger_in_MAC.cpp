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
    int n, t;
    cin >> n >> t;
    vector<PII> mes(n);
    for (int i = 0; i < n; i++) {
        cin >> mes[i].second >> mes[i].first;
    }
    sort(mes.begin(), mes.end());

    int num = 0;
    for (int l = 0; l < n; l++) {
        priority_queue<int> h;
        int time = 0;
        for (int r = l; r < n; r++) {
            h.push(mes[r].second);
            time += mes[r].second;
            while (!h.empty() && mes[r].first - mes[l].first + time > t) {
                time -= h.top();
                h.pop();
            }
            num = max(num, (int)h.size());
        }
    }

    cout << num << '\n';
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