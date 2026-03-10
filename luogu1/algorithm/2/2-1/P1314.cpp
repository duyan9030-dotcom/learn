#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
ll cnt[1000005]; //>=i的数有几个
ll pre[1000005];
ll n, m, s, maxw = -1, minw = 1e7;
ll ls[200005], rs[200005];
ll w[200005], v[200005];
ll check(int W)
{
    ll y = 0;
    cnt[0] = 0;
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (w[i] >= W)
        {
            cnt[i] = cnt[i - 1] + 1;
            pre[i] = v[i] + pre[i - 1];
        }
        else
        {
            cnt[i] = cnt[i - 1];
            pre[i] = pre[i - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        y += (cnt[rs[i]] - cnt[ls[i] - 1]) * (pre[rs[i]] - pre[ls[i] - 1]);
    }
    // for (int i = 1; i <= n; i++)
    //     cout << cnt[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    //     cout << pre[i] << " ";
    return y;
}
//二分答案+前缀和优化枚举
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i] >> v[i];
        maxw = max(maxw, w[i]);
        minw = min(minw, w[i]);
    }
    for (int i = 1; i <= m; i++)
        cin >> ls[i] >> rs[i];
    ll ans = 1e15;
    ll l = minw - 1, r = maxw + 1;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll y = check(mid);
        if (y < s)
        {
            r = mid - 1;
            ans = min(ans, s - y);
        }
        else
        {
            l = mid + 1;
            ans = min(ans, y - s);
        }
    }
    cout << ans;
}