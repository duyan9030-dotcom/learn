#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
vector<int> prime;
bool vis[50005];
ll m[50000];
vector<int> mp;
void build()
{
    for (int i = 2; i < 50000; i++)
    {
        if (!vis[i])
        {
            prime.push_back(i);
            for (int j = 2 * i; j < 50000; j += i)
            {
                vis[j] = true;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m1, m2;
    cin >> n >> m1 >> m2;
    memset(m, 0, sizeof(m));
    build();
    vector<ll> s(n);
    for (ll &x : s)
        cin >> x;
    if (m1 == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i : prime) // 分解m1
    {
        while (m1 % i == 0)
        {
            m[i]++;
            m1 /= i;
        }
    }
    for (int i = 0; i < 50000; i++) //
    {
        if (m[i] != 0)
        {
            m[i] *= m2;
            mp.push_back(i); // m1^m2所具有的质数因子
        }
    } // 分解m1^m2,每一个Si都必须拥有至少一个这些因子,否则不可能,如果可以就是同一个质数因子比值最大的向上取整
    ll ans = -1;
   
    for (ll x : s)
    {
        bool y = false;
        for (int i : mp)
            if (x % i != 0)
                y = true;
        if (y)
            continue;
        ll k = -1;
        for (int i : mp)
        {
            int cur = 0;
            while (x % i == 0)
            {
                x /= i;
                cur++; // Si中因子i的数量
            }
            k = max(k, (m[i] + cur - 1) / cur);
        }
        ans = ans == -1 ? k : min(ans, k);
    }
    cout << ans << endl;
}