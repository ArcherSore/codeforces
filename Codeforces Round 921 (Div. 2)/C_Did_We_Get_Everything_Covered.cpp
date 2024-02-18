#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <numeric>
#include <set>
#include <stack>
#include <map>
using namespace std;

typedef long long LL;

void func(string &s, int lvl, int n, int k) {
    set<char> ch;
    string t;
    for (char c : s) {
        ch.emplace(c);
        if (ch.size() == k) {
            ch.clear();
            t.push_back(c);
            if (t.size() == n) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
    ch.emplace('a' + k);
    char pre = 'a' - 1;
    for (char c : ch) {
        if (c - pre != 1) {
            t.push_back(c - 1);
            break;
        }
        pre = c;
    }
    while (t.size() < n) {
        t.push_back('a');
    }
    
    cout << t << '\n';
    return;
}

void solve() {
    int n, k, m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    func(s, 0, n, k);
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