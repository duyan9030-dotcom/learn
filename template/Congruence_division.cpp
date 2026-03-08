#include <bits/stdc++.h>
using namespace std;
#define ll long long
// const int mod = 1e9 + 7;
//  除法同余必须保证
//  1.a/b可以整除
//  2.mod为质数
//  3.b和mod互质
//  逆元:((b)^(mod-2))%mod;
ll power(ll a, ll p, ll mod)
{
    ll ans = 1;
    while (p != 0)
    {
        if (p & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}
ll f(ll a, ll b, ll mod)
{
    ll inv = power(b, mod - 2, mod);
    return ((a % mod) * inv) % mod;
}
// 逆元线性递推公式
// 求1-n每个数字%p的逆元
int inv[3000005];
void build(int n, int p)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (int)(p - (ll)inv[p % i] * (p / i) % p);
    // 逆元线性递推公式
}
// 阶乘逆元线性递推公式
// 阶乘表
ll fac[1005];
// 逆元表
ll invs[1005];
void build(int n, int mod)
{
    inv[0] = 1;
    for (int i = 1; i <= 1000; i++)
        fac[i] = fac[i - 1] * i;
    // inv[0] = 1;
    // for (int i = 1; i <= 1000; i++)
    //     inv[i] = power(fac[i], mod - 2, mod);
    inv[1000] = power(fac[1000], mod - 2, mod);
    for (int i = 999; i >= 1; i--)
        inv[i] = ((ll)(i + 1) * inv[i + 1]) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int mod = 7;
    ll b = 3671613L;
    ll a = 67312L * b;
    cout << f(a, b, mod) << endl;
    cout << (a / b) % mod << endl;
    cout << a % mod;
}