#include <bits/stdc++.h>
using namespace std;

using LL = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> d(n);
    for (auto &x : d) {
        cin >> x;
    }
    
    priority_queue<int> pq;
    int m = n / (k + 1), lst = 0;
    LL res = 0;
    for (int i = m; i >= 1; i--) {
        while (lst <= n - i * (k + 1)) {
            pq.push(d[lst]);
            lst++;
        }
        res += pq.top();
        pq.pop();
    }
    cout << res << '\n';
}
  
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int T = 1;
    cin >> T;
  
    while(T--){
        solve();
    }
  
    return 0;
}