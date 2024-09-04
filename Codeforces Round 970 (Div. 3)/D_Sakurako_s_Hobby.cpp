// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 200005;

int F[MAXN];
bool visited[MAXN];
int color[MAXN];
int cycleSize[MAXN];

void computeF(int start, const vector<int>& p) {
    int i = start;
    vector<int> cycle_nodes;
    while (!visited[i]) {
        visited[i] = true;
        cycle_nodes.push_back(i);
        i = p[i];
    }
    
    // Determine if it's a cycle
    int cycle_start = i;
    int blackCount = 0;
    bool inCycle = false;

    for (int node : cycle_nodes) {
        if (node == cycle_start) inCycle = true;
        if (inCycle) {
            blackCount += (color[node] == 0);
            cycleSize[node] = cycle_nodes.size();
        }
    }

    // Set F values
    for (int node : cycle_nodes) {
        F[node] = blackCount;
    }
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;  // Convert to 0-based index
    }
    
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i) {
        color[i] = (s[i] == '0' ? 0 : 1);
    }
    
    memset(F, -1, sizeof(int) * n);
    memset(visited, false, sizeof(bool) * n);
    memset(cycleSize, 0, sizeof(int) * n);
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (F[p[i]] != -1 && cycleSize[i] == 0) {
                F[i] = F[p[i]] + (color[i] == 0 ? 1 : 0);
            } else {
                computeF(i, p);
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        cout << F[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}
