#include <bits/stdc++.h>
using namespace std;
int n, k, c = 0;
int a[25];
bool zhishu(int a)
{
    if(a==0||a==1)
        return false;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0)
            return false;
    return true;
}
void dfs(int x, int sum,int now)
{
    if (x==k+1)
    {
        if (zhishu(sum))
            c++;
        return;
    }
    for (int i = now; i <=n; i++)
        dfs(x+1,sum+a[i],i+1);
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(1,0,1);
    cout << c;
    return 0;
}
