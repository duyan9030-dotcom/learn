#include <bits/stdc++.h>
using namespace std;
int ans = 0, n, k;
int a[25];
bool isprime(int x)//判断质数
{
    if (x == 1)
        return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}
void dfs(int now, int sum, int sid)//深度优先搜素
{
    if (now == k)//若加够k个则判断质数
    {
        if (isprime(sum))
        {
            ++ans;
        }
        return;
    }
    for (int i = sid; i <= n - k + now + 1; ++i)
        dfs(now + 1, sum + a[i], i + 1);
    return;
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0,1);
    cout << ans;
    return 0;
}