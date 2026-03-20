#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int v, n;
int a[35];
int dp[35][20005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> v >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j < a[1]; j++)
        dp[1][j] = j;
    for (int j = a[1]; j <= v; j++)
        dp[1][j] = j - a[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < a[i]; j++)//不能拿
        {
            dp[i][j] = dp[i - 1][j];
        }
        for (int j = a[i]; j <= v; j++)//可以拿
        {
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - a[i]]);
        }
    }
    cout << dp[n][v];
}