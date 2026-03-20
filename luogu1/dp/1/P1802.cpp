#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
ll n, x;
ll lose[1005], win[1005], use[1005];
ll dp[1005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= use[i]; j--)
            dp[j] = max(dp[j - use[i]] + win[i], dp[j] + lose[i]);
        for (int j = use[i]-1; j >= 0; j--) // 药不够打赢第i个人
            dp[j] = dp[j] + lose[i];
    }
    cout << 5 * dp[x];
}