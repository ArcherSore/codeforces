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
    // 找到最大的数的位置pos
    int pos = 0;
    for (int i = 0; i < n; i++) {
        printf("? %d %d %d %d\n", i, i, pos, pos);
        char opt;
        cin >> opt;
        if (opt == '>') {
            pos = i;
        }
    }
    // 找到或运算最大的集合
    vector<int> res;
    int maxx = 0;
    for (int i = 0; i < n; i++) {
        if (i == pos) {
            continue;
        }
        printf("? %d %d %d %d\n", pos, i, pos, maxx);
        char opt;
        cin >> opt;
        if (opt == '>') {
            maxx = i;
            res.clear();
            res.push_back(i);
        } else if (opt == '=') {
            res.push_back(i);
        }
    }
    // 找到集合中的最小值
    int minp = *res.begin();
    for (int i = 0; i < res.size(); i++) {
        printf("? %d %d %d %d\n", res[i], res[i], minp, minp);
        char opt;
        cin >> opt;
        if (opt == '<') {
            minp = res[i];
        }
    }

    printf("! %d %d\n", pos, minp);
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}