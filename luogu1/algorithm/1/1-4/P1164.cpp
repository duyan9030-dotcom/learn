#include<iostream>
#include<vector>
using namespace std;
int dp[105][10005]={0},price[105];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n;i++)
        cin >> price[i];
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= m;j++)
        {
            if(j==price[i])
                dp[i][j] = dp[i - 1][j] + 1;
            if(j>price[i])
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - price[i]];
            if(j<price[i])
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][m];
}