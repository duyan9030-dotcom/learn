#include <bits/stdc++.h>
using namespace std;
int Ehrlich1(int n)
{
    vector<int> vis(n + 1);
    for (int i = 2; i * i <= n; i++)
        if (!vis[i])
            for (int j = i * i; j <= n; j += i)
                vis[j] = true;
    int cnt = 0;
    for (int i = 2; i <= n; i++)
        if (!vis[i])
            cnt++;
    return cnt;
}
int Ehrlich2(int n)
{
    if (n <= 1)
        return 0;
    vector<int> vis(n + 1);
    int cnt = (n + 1) / 2;
    for (int i = 3; i * i <= n; i+=2)
        if (!vis[i])
            for (int j = i * i; j <= n; j += 2*i)
                if (!vis[j])
                {
                    vis[j] = true;
                    cnt--;
                }
    return cnt;
}
int Euler(int n)
{
    vector<int> vis(n + 1);
    vector<int> prime(n / 2 + 1);
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            prime[cnt++] = i;
        }
        for (int j = 0; j < cnt; j++)
        {
            if (i * prime[j] > n)
                break;
            vis[i * prime[j]] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    cout << Ehrlich2(10000) << " " << Euler(10000);
}