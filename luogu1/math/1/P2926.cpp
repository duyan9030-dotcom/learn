#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
bool primes[1000005]; // i不是质数吗
int cnt[1000005];
void build()
{
    for (int i = 2; i*i <= 1000000; i++)
    {
        if (!primes[i])
        {
            for (int j = 2 * i; j <= 1000000; j += i)
                primes[j] = true;
        }
    }
}
int count(int a)
{
    int ans = 0;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            ans += cnt[i];
            if (i != a / i)
                ans += cnt[a / i];
        }
    }
    ans += cnt[a]-1;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    build();
    vector<int> a(n);
    memset(cnt, 0, sizeof(cnt));
    for (int &x : a)
    {
        cin >> x;
        cnt[x]++;
    }
    // 对于1，他只能拍1
    //  对于质数，统计1和它本身的数量
    //  对于非质数,统计1和他的因子的数量
    for (int i = 0; i < n; i++)
    {
        int ans = 0;
        if (a[i] == 1)
        {
            ans = cnt[1] - 1;
        }
        else if (!primes[a[i]])
        {
            ans = cnt[a[i]] + cnt[1] - 1;
        }
        else
        {
            ans = count(a[i]) + cnt[1];
        }
        cout << ans << endl;
    }
}