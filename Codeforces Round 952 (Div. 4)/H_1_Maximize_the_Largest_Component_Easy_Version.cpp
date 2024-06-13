// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(vector<vector<char>> &grid, vector<vector<int>> &mark, int x, int y, int id, map<int, int> &num) {
    mark[x][y] = id;
    num[id]++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) {
            continue;
        }
        if (grid[xx][yy] == '#' && mark[xx][yy] == 0) {
            dfs(grid, mark, xx, yy, id, num);
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> mark(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == '.') {
                mark[i][j] = -1;
            }
        }
    }

    int id = 0;
    map<int, int> num;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mark[i][j] == 0) {
                dfs(grid, mark, i, j, ++id, num);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        set<int> caled;
        int tot = 0;
        for (int j = 0; j < m; j++) {
            if (mark[i][j] == -1) {
                tot += 1;
                if (i >= 1 && mark[i - 1][j] != -1 && caled.find(mark[i - 1][j]) == caled.end()) {
                    tot += num[mark[i - 1][j]];
                    caled.insert(mark[i - 1][j]); 
                }
                if (i < n - 1 && mark[i + 1][j] != -1 && caled.find(mark[i + 1][j]) == caled.end()) {
                    tot += num[mark[i + 1][j]];
                    caled.insert(mark[i + 1][j]); 
                }
            } else {
                if (mark[i][j] != 0 && caled.find(mark[i][j]) == caled.end()) {
                    tot += num[mark[i][j]];
                    caled.insert(mark[i][j]);
                }
                if (i >= 1 && mark[i - 1][j] != -1 && caled.find(mark[i - 1][j]) == caled.end()) {
                    tot += num[mark[i - 1][j]];
                    caled.insert(mark[i - 1][j]); 
                }
                if (i < n - 1 && mark[i + 1][j] != -1 && caled.find(mark[i + 1][j]) == caled.end()) {
                    tot += num[mark[i + 1][j]];
                    caled.insert(mark[i + 1][j]); 
                }
            }
        }
        ans = max(ans, tot);
    }

    for (int j = 0; j < m; j++) {
        set<int> caled;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            if (mark[i][j] == -1) {
                tot += 1;
                if (j >= 1 && mark[i][j - 1] != -1 && caled.find(mark[i][j - 1]) == caled.end()) {
                    tot += num[mark[i][j - 1]];
                    caled.insert(mark[i][j - 1]); 
                }
                if (j < m - 1 && mark[i][j + 1] != -1 && caled.find(mark[i][j + 1]) == caled.end()) {
                    tot += num[mark[i][j + 1]];
                    caled.insert(mark[i][j + 1]); 
                }
            } else {
                if (mark[i][j] != -1 && caled.find(mark[i][j]) == caled.end()) {
                    tot += num[mark[i][j]];
                    caled.insert(mark[i][j]);
                }
                if (j >= 1 && mark[i][j - 1] != -1 && caled.find(mark[i][j - 1]) == caled.end()) {
                    tot += num[mark[i][j - 1]];
                    caled.insert(mark[i][j - 1]); 
                }
                if (j < m - 1 && mark[i][j + 1] != -1 && caled.find(mark[i][j + 1]) == caled.end()) {
                    tot += num[mark[i][j + 1]];
                    caled.insert(mark[i][j + 1]); 
                }
            }
        }
        ans = max(ans, tot);
    }

    cout << ans << '\n';
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