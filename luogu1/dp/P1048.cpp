#include <bits/stdc++.h>
using namespace std;
int dp1[105][1005];
int dp[1005];
int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> value(m + 1);
    vector<int> time(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> time[i] >> value[i];
    // for (int i = 1; i <= m; i++)
    // {
    //     for (int j = 1; j <= t; j++)
    //     {
    //         if (j - time[i] < 0)
    //             dp[i][j] = dp[i - 1][j];
    //         else
    //         {
    //             dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - time[i]] + value[i]);
    //         }
    //     }
    // }
    // cout << dp[m][t];
    for (int i = 1; i <= m;i++)
        for (int j = t; j >=time[i];j--)
            dp[j] = max(dp[j], dp[j - time[i]]+value[i]);
    cout << dp[t];
}