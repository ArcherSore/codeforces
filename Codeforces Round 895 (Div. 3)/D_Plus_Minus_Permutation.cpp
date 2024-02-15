#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    long long n = max(a, b);
	long long m = min(a, b);
	if(n % m == 0)
	    return m;
	return gcd(n % m, m);
}

long long gcb(long long a, long long b) {
	long long x = gcd(a, b);
    return a * b / x;
}

void solve(long long n, long long x, long long y) {
    long long num_x = n / x, num_y = n / y, num_common = n / gcb(x, y);
    num_x -= num_common, num_y -= num_common;
    long long ans = 0;
    ans += (2 * n - num_x + 1) * num_x / 2;
    ans -= (1 + num_y) * num_y / 2;
    cout << ans << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        solve(n, x, y); 
    }
    return 0;
}