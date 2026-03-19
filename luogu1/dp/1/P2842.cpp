#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int n, w;
int a[1005];
int dp[10002];//凑出i元最少几张纸币
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= w; j++)
        dp[j] = 1e9;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= w; j++)
            dp[j] = min(dp[j], dp[j - a[i]] + 1);
    cout << dp[w];
    return 0;
}
