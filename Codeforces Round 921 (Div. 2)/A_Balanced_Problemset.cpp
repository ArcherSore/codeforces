#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <numeric>
#include <vector>
#include <stack>
#include <map>
#include <set>
using namespace std;

typedef long long LL;

void fac(int x, vector<int> &factor) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            while (x % i == 0) {
                x /= i;
                factor.push_back(i);
            }
        }
    }
    if (x != -1) {
        factor.push_back(x);
    }
    return;
}

int ans = 1;
void cal(int i, int res, int x, int n, vector<int> &factor) {
    if (i == (int)factor.size() || x / res < n) return;

    // Include the current factor and recurse
    cal(i + 1, res * factor[i], x, n, factor);

    // Exclude the current factor and recurse
    cal(i + 1, res, x, n, factor);

    ans = max(ans, res);
    return;
}

void generateCombinations(int i, vector<int> &combination, const vector<int> &factor) {
    if (i == (int)factor.size()) {
        // Print or process the combination
        for (int num : combination) {
            cout << num << " ";
        }
        cout << '\n';
        return;
    }

    // Include the current factor in the combination
    combination.push_back(factor[i]);
    generateCombinations(i + 1, combination, factor);
    combination.pop_back();  // Backtrack

    // Exclude the current factor in the combination
    generateCombinations(i + 1, combination, factor);
}

void solve() {
    ans = 1;
    int x, n;
    cin >> x >> n;
    vector<int> factor;
    fac(x, factor);
    cal(0, 1, x, n, factor);

    // Uncomment the following line to print all combinations
    // vector<int> combination;
    // generateCombinations(0, combination, factor);

    cout << ans << '\n';
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
