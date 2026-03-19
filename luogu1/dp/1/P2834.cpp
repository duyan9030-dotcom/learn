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
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= w; j++)
        {
            dp[j] += dp[j - a[i]] % mod;
            dp[j] %= mod;
        }
    }
    cout << dp[w];
}