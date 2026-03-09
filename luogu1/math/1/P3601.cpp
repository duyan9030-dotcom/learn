#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 666623333;
bool vis[1000005];
vector<int> prime;
ll phi[1000005], res[1000005];
//欧拉函数
//坐标映射
//埃氏筛
void build()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j <= 1000000; j += i)
                vis[j] = true;
        }
    }
}//获取1e6以内的质数因子
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll l, r;
    cin >> l >> r;
    build();
    int len = r - l + 1;
    for (int i = 0; i < len;i++)
    {
        phi[i] = l + i;
        res[i] = l + i;
    }
    for(int p:prime)
    {
        ll start = (l + p - 1) / p * p;
        for (ll j = start; j <= r;j+=p)
        {
            int idx = j - l;
            phi[idx] = phi[idx] / p * (p - 1);
            while(res[idx]%p==0)
                res[idx] /= p;
        }
    }
    ll ans = 0;
    for (int i = 0; i < len;i++)
    {
        if(res[i]>1)
            phi[i] = phi[i] / res[i] * (res[i] - 1);
        ans = (ans + (l + i - phi[i])) % mod;
    }
    cout << ans;
}