#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
const int N = 301;
const int M = 1e9 + 7;
int dp[3][N][N][N];
int t[N+1][N+1][N+1];
char ch[N];
int n,cnt,qu;
int dir[3][2] = {{1,2},{0,2},{0,1}};
int lowbit(const int x) {return x & -x;}
void add(const int x,const int y,const int z,const int val)
{
    for(int i = x;i<=cnt+1;i+=lowbit(i))
        for(int j = y;j<=cnt+1;j+=lowbit(j))
            for(int k = z;k<=cnt+1;k+=lowbit(k)) t[i][j][k] = (t[i][j][k] + val)%M;
}
int q(const int x,const int y,const int z)
{
    int ret = 0;
    for(int i = x;i;i-=lowbit(i))
        for(int j = y;j;j-=lowbit(j))
            for(int k = z;k;k-=lowbit(k)) ret= (t[i][j][k] + ret)%M;
    return ret;
}
void solve() 
{
    cin >> n >> qu;
    for(int i = 1;i<=n;i++) cin >> ch[i];

    if(ch[n] == '?') dp[0][1][0][0] = dp[1][0][1][0] = dp[2][0][0][1] = 1,cnt++;
    else
    {
        int x = 0;
        if(ch[n] == 'b') x = 1;
        else if(ch[n] == 'c') x = 2;
        dp[x][0][0][0] = 1;
    }

    for(int i = n-1;i>=1;i--)
    {
        if(ch[i] == '?')
        {
            for(int j = 0;j<=cnt;j++)
            {
                for(int k = 0;k<=cnt-j;k++)
                {
                    int p = cnt - j - k;
                    dp[0][j+1][k][p] = (dp[1][j][k][p] + dp[2][j][k][p])%M;
                    dp[1][j][k+1][p] = (dp[0][j][k][p] + dp[2][j][k][p])%M;
                    dp[2][j][k][p+1] = (dp[0][j][k][p] + dp[1][j][k][p])%M;
                }
            }
            cnt++;
        }
        else
        {
            int x = 0;
            if(ch[i] == 'b') x = 1;
            else if(ch[i] == 'c') x = 2;
            for(int j = 0;j<=cnt;j++)
            {
                for(int k = 0;k<=cnt-j;k++)
                {
                    int p = cnt - j - k;
                    dp[x][j][k][p] = (dp[dir[x][0]][j][k][p] + dp[dir[x][1]][j][k][p])%M;
                    dp[dir[x][0]][j][k][p] = dp[dir[x][1]][j][k][p] = 0;
                }
            }
        }
    }
    for(int j = 0;j<=cnt;j++)
    {
        for(int k = 0;k<=cnt-j;k++)
        {
            int p = cnt - j - k;
            int ret = 0;
            for(int q = 0;q<=2;q++) ret = (ret + dp[q][j][k][p])%M;
            //cerr << j << ' ' << k << ' ' << p << ' ' << ret << '\n';
            add(j+1,k+1,p+1,ret);
        }
    }
    while(qu--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        x++,y++,z++;
        x = min(x,cnt+1),y = min(y,cnt+1),z = min(z,cnt+1);
        //cerr << x << ' ' << y << ' ' << z << '\n';
        cout << q(x,y,z) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}