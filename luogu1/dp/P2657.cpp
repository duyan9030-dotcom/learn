#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 11;
int dp[maxn][11][2];
void build(int n)
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= 10; j++)
            dp[i][j][0] = dp[i][j][1] = -1;
}
int f(int num, int offset, int len, int pre, int free)
{
    if (len == 0)
        return 1;
    if (dp[len][pre][free] != -1)
        return dp[len][pre][free];
    int cur = num / offset % 10;
    int ans = 0;
    if (free == 0)
    {
        if (pre == 10)
        {
            ans += f(num, offset / 10, len - 1, 10, 1);
            for (int i = 1; i < cur; i++)
                ans += f(num, offset / 10, len - 1, i, 1);
            ans += f(num, offset / 10, len - 1, cur, 0);
        }
        else
        {
            for (int i = 0; i <= 9; i++)
                if (abs(i - pre) >= 2)
                    if (i < cur)
                        ans += f(num, offset / 10, len - 1, i, 1);
                    else if (i == cur)
                        ans += f(num, offset / 10, len - 1, cur, 0);
        }
    }
    else
    {
        if (pre == 10)
        {
            ans += f(num, offset / 10, len - 1, 10, 1);
            for (int i = 1; i <= 9; i++)
                ans += f(num, offset / 10, len - 1, i, 1);
        }
        else
        {
            for (int i = 0; i <= 9; i++)
                if (abs(i - pre) >= 2)
                    ans += f(num, offset / 10, len - 1, i, 1);
        }
    }
    dp[len][pre][free] = ans;
    return ans;
}
int cnt(int num)
{
    if (num == 0)
        return 1;
    int len = 1;
    int offset = 1;
    int tmp = num / 10;
    while (tmp > 0)
    {
        len++;
        offset *= 10;
        tmp /= 10;
    }
    build(len);
    return f(num, offset, len, 10, 0);
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1);
}