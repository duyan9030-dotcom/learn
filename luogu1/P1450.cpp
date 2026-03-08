#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll n, s, v[4], c[4];
ll dp[100005];
void build()
{
    dp[0] = 1;
    for (int i = 0; i <= 3; i++)
        for (int j = v[i]; j <= 100000; j++)
            dp[j] += dp[j - v[i]];
}
void solve()
{
    for (int i = 0; i < 4; i++)
        cin >> c[i];
    cin >> s;
    ll ill = 0;
    for (int status = 1; status <= 15; status++)
    {
        ll t = s;
        int sign = -1;
        for (int j = 0; j <= 3; j++)
        {
            if (((status >> j) & 1) == 1)
            {
                t -= v[j] * (c[j] + 1);
                sign = -sign;
            }
        }
        if (t >= 0)
            ill += dp[(int)t] * sign;
    }
    cout << dp[s] - ill << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0; i < 4; i++)
        cin >> v[i];
    build();
    cin >> n;
    while (n--)
        solve();
}