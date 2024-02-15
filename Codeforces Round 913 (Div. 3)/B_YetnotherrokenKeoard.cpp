#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <set>
using namespace std;

typedef long long LL;

void solve() {
    string s, ans;
    cin >> s;

    int len = s.size();
    vector<int> flag(len + 1);
    stack<int> lower, upper;

    for (int i = 0; i < len; i++) {
        if (s[i] == 'b') {
            if (lower.empty()) 
                continue;
            flag[lower.top()] = 1;
            lower.pop();
        } else if (s[i] == 'B') {
            if (upper.empty())
                continue;
            flag[upper.top()] = 1;
            upper.pop();
        } else {
            ans.push_back(s[i]);
            if (islower(s[i])) lower.push(i);
            else upper.push(i);
        }
    }
    for (int i = 0; i < len; i++) {
        if (!flag[i] && s[i] != 'B' && s[i] != 'b') {
            cout << s[i];
        }
    }
    cout << '\n';
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}