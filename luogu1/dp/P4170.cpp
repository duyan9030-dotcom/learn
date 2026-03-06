#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    const int n = s.size();
    int dp[n][n];
    dp[n - 1][n - 1] = 1;
    for (int i = 0; i < n - 1; i++)
    {
        dp[i][i] = 1;
        dp[i][i + 1] = s[i] == s[i + 1] ? 1 : 2;
    }
    for (int l = n - 3; l >= 0; l--)
    {
        for (int r = l + 2; r < n; r++)
        {
            if (s[l] == s[r])
                dp[l][r] = dp[l][r - 1];
            // dp[l][r] = dp[l+1][r];
            else
            {
                int ans = INT_MAX;
                for (int m = l; m < r; m++)
                    ans = min(ans, dp[l][m] + dp[m + 1][r]);
                dp[l][r] = ans;
            }
        }
    }
    cout << dp[0][n - 1];
    return 0;
}