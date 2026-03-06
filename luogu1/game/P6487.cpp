//斐波那契博弈
#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
ll maxn = 1e16 + 1;
ll f[200];
int size;
void build()
{
    f[0] = 1, f[1] = 2;
    size = 1;
    while(f[size]<=maxn)
    {
        f[size + 1] = f[size] + f[size - 1];
        size++;
    }
}
ll bs(ll n)
{
    int l = 0;
    int r = size;
    int m;
    ll ans = -1;
    while(l<=r)
    {
        m = (l + r) / 2;
        if(f[m]<=n)
        {
            ans = f[m];
            l = m + 1;
        }
        else{
            r = m - 1;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    build();
    long long ans = -1, find;
    while(n!=1&&n!=2)
    {
        find = bs(n);
        if(n==find)
        {
            ans = find;
            break;
        }
        else{
            n -= find;
        }
    }
    if(ans!=-1)
        cout << ans;
    else
        cout << n;
}