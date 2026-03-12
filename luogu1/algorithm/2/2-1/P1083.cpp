#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
const int mn = 1000005;
ll diff[mn];
ll d[mn], s[mn], t[mn];
ll r[mn];
int n, m;
bool check(int mid)
{
    memset(diff, 0, sizeof(ll) * (n + 2));
    for (int i = 1; i <= mid; i++)
    {
        diff[s[i]] += d[i];
        diff[t[i] + 1] -= d[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum +=diff[i];
        if (sum > r[i])
            return false;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> r[i];
    for (int i = 1; i <= m; i++)
        cin >> d[i] >> s[i] >> t[i];
    int l = 1, r = m;
    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    if (ans == m)
        cout << 0;
    else
        cout << -1 << endl
             << ans+1 << endl;
}