#include <bits/stdc++.h>
using namespace std;
int nums[1005];
int n;
int mod = 19650827;
int compute()
{
    int dp[1005][1005][2];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            dp[i][i + 1][0] = 1;
            dp[i][i + 1][1] = 1;
        }
    }
    for (int l = n - 2; l >= 1; l--)
    {
        for (int r = l+2; r <= n; r++)
        {
            if (nums[l] < nums[l + 1])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][0]) % mod;
            if (nums[l] < nums[r])
                dp[l][r][0] = (dp[l][r][0] + dp[l + 1][r][1]) % mod;
            if (nums[r] > nums[l])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][0]) % mod;
            if (nums[r] > nums[r - 1])
                dp[l][r][1] = (dp[l][r][1] + dp[l][r - 1][1]) % mod;
        }
    }
    return (dp[1][n][0] + dp[1][n][1]) % mod;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> nums[i];
    if (n == 1)
        cout << 1;
    else
        cout << compute();
    return 0;
}