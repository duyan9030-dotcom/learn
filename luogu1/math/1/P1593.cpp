#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 9901;
vector<int> pf;
int cnt[1000005];
ll power(int a, int p)
{
    int ans = 1;
    while (p)
    {
        if (p & 1)
        {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}
ll sum(ll a, ll p)
{
    a %= mod;
    if (p == 0)
        return 1;
    if(a==0)
        return 1;
    if(a==1)
        return (p + 1) % mod;
    if(p%2==1)
        return (sum(a, p / 2) * (1 + power(a, p / 2 + 1))) % mod;
    else
        return (sum(a, p / 2 - 1) * (1 + power(a, p / 2 + 1)) + power(a, p /2)) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    ll ans = 1;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            int cnt = 0;
            while(a%i==0)
            {
                cnt++;
                a /= i;
            }
            ans = (ans * sum(i, cnt * b)) % mod;
        }
    }
    if(a>1)
        ans = (ans * sum(a, b)) % mod;
    cout << ans;
    return 0;
}