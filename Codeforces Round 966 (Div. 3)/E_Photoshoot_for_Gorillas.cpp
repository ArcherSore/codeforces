#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using LL = long long;

void calculate_prefix_sum(const vector<vector<int>>& grid, vector<vector<LL>>& prefix_sum) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            prefix_sum[i+1][j+1] = grid[i][j]
                + prefix_sum[i][j+1]
                + prefix_sum[i+1][j]
                - prefix_sum[i][j];
        }
    }
}

LL get_kxk_sum(const vector<vector<LL>>& prefix_sum, int x1, int y1, int x2, int y2) {
    return prefix_sum[x2+1][y2+1]
        - prefix_sum[x1][y2+1]
        - prefix_sum[x2+1][y1]
        + prefix_sum[x1][y1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, w;
        cin >> n >> m >> k >> w;

        vector<int> gorilla_heights(w);
        for (int i = 0; i < w; ++i) {
            cin >> gorilla_heights[i];
        }

        vector<vector<int>> weight(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int r1 = max(0, i - k + 1);
                int r2 = min(n - k, i);
                int c1 = max(0, j - k + 1);
                int c2 = min(m - k, j);
                weight[i][j] = (r2 - r1 + 1) * (c2 - c1 + 1);
            }
        }

        vector<pair<int, pair<int, int>>> cells;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cells.push_back({weight[i][j], {i, j}});
            }
        }
        sort(cells.rbegin(), cells.rend());

        sort(gorilla_heights.rbegin(), gorilla_heights.rend());

        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (int i = 0; i < min(w, n * m); ++i) {
            int x = cells[i].second.first;
            int y = cells[i].second.second;
            grid[x][y] = gorilla_heights[i];
        }

        vector<vector<LL>> prefix_sum(n + 1, vector<LL>(m + 1, 0));
        calculate_prefix_sum(grid, prefix_sum);

        LL max_spectacle = 0;
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= m - k; ++j) {
                max_spectacle += get_kxk_sum(prefix_sum, i, j, i + k - 1, j + k - 1);
            }
        }

        cout << max_spectacle << endl;
    }

    return 0;
}