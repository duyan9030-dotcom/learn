#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n, w;
int a[1005];
int dp[10005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i - a[j] >= 0)
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[w];
}