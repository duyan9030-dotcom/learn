#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, m;
ll a[10005], b[10005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i];
    vector<ll> dp(t + 1); //
    for (int i = 1; i <= m; i++)
        for (int j = a[i]; j <= t; j++)
            dp[j] = max(dp[j - a[i]] + b[i], dp[j]);
    cout << dp[t];
}