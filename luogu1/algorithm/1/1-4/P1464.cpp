#include <bits/stdc++.h>
using namespace std;
long long dp[25][25][25];
bool vis[25][25][25];
long long w(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20,20,20);
    if(vis[a][b][c])
        return dp[a][b][c];
    if (a < b && b < c)
    {
        dp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1)-w(a, b-1, c);
    }
    else
    {
        dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1)-w(a-1, b-1, c-1);
    }
    vis[a][b][c] = true;
    return dp[a][b][c];
}
int main()
{
    long long a, b, c;
    memset(vis, false, sizeof(vis));
    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, w(a, b, c));
    }
    return 0;
}