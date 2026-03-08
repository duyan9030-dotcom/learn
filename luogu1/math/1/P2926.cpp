#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
bool primes[1000005]; // i是质数吗
int cnt[1000005];
void build()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (!primes[i])
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                primes[j] = true;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    // 对于质数，统计1和它本身的数量
    // 对于非质数,统计1和他的因子的数量
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        if (a[i] == 1)
        {
            ans = cnt[a[i]];
        }
        else if (!primes[a[i]])
        {
            ans = cnt[a[i]] + cnt[1];
        }
        else
        {
        }
    }
}