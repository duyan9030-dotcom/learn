#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int n;
int l[20005], r[20005];
int dp[20005][2];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    dp[1][0] = r[1] - 1 + r[1] - l[1];
    dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0] + 1 + abs(l[i - 1] - r[i]) + r[i] - l[i], dp[i - 1][1]  + abs(r[i - 1] - r[i]) + r[i] - l[i] + 1);
        dp[i][1] = min(dp[i - 1][0] + 1 + abs(l[i - 1] - l[i]) + r[i] - l[i], dp[i - 1][1]  + abs(r[i - 1] - l[i]) + r[i] - l[i] + 1);
    }
    cout << min(dp[n][0] + n - l[n], dp[n][1] + n - r[n]);
}