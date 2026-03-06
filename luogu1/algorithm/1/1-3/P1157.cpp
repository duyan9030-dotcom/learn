#include <bits/stdc++.h>
using namespace std;
int n, r;
int zh[25];
void dfs(int x,int now)
{
    if(x==r+1)
    {
        for (int i = 1; i <= r;i++)
            cout<<setw(3)<<zh[i];
        cout <<endl;
        return;
    }
    for (int i = now; i <= n;i++)
    {
        zh[x] = i;
        dfs(x + 1, i + 1);
    }
}
int main()
{
    cin >> n >> r;
    dfs(1,1);
    return 0;
}