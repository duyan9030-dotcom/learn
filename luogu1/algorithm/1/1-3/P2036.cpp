#include <bits/stdc++.h>
using namespace std;
int a[15], b[15],f[15];
int n,mi=INT_MAX,ji=1,sum=0;
void dfs(int x)
{
    if(x>n)
        return;
    for (int i = 1; i <=n;i++)
    {
        if(f[i]==0)
        {
            ji *= a[i];
            sum += b[i];
            mi = min(mi, abs(ji - sum));
            f[i] = 1;
            dfs(x + 1);
            f[i] = 0;
            ji /= a[i];
            sum -= b[i];
        }
    }
}
int main()
{

    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i] >> b[i];
    dfs(1);
    cout << mi;
    return 0;
}