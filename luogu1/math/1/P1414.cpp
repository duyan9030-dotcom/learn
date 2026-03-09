#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int cnt[1000005];
int ans[10005];
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,maxv=-1,x;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> x;
        cnt[x]++;
        maxv = max(maxv, x);
    }
    for (int g = 1; g <= maxv;g++)
    {
        int count = 0;
        //枚举最大公约数
        for (int i = g; i <= maxv;i+=g)
            count += cnt[i];
        //选k<=count时，最大公约数至少是g
        if(count>0)
            ans[count] = max(ans[count], g);
    }
    // 选 k 个人的最大 GCD 至少不小于选 k+1 个人的
    for (int i = n - 1; i >= 1;i--)
        ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n;i++)
        cout << ans[i] << endl;
    return 0;
}