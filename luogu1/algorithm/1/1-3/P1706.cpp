#include <bits/stdc++.h>
using namespace std;
int n;
int zh[10],vis[10];
void dfs(int x)
{
    if (x == n + 1)
    {
        for (int i = 1; i <= n;i++)
            cout << setw(5) << zh[i];
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            zh[x] = i;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    return 0;
}