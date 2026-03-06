#include <bits/stdc++.h>
using namespace std;
char l[55][55];
int n, m;
void dfs(int i, int j)
{
    if (i < 1 || i > m || j < 1 || j > n || l[i][j] == '0')
        return;
    l[i][j] = '1';
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1); 
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(l, '0', 55 * 55);
        int island = 0;
        cin >> m >> n;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> l[i][j];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(l[i][j]=='1')
                {
                    island++;
                    dfs(i, j);
                }
            }
        }//把岛内的0全部变为1
        // for (int i = 1; i <= m; i++)
        // {
        //     for (int j = 1; j <= n; j++)
        //     {
        //         if (l[i][j] == '1')
        //         {
                    
        //         }
        //     }
        // } // 把岛内的0全部变为1
        cout << island << endl;
    }
}