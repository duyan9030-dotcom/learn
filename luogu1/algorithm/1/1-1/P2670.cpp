#include <bits/stdc++.h>
using namespace std;
char di[105][105];
int main()
{
    int n, m;
    cin >> n >> m;
    memset(di, '0', sizeof(di)); // 不可以给二维数组char di[105][105]={‘0’};这样初始化，必须这样
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char s;
            cin >> s;
            if (s == '*')
            {
                di[i][j] = '*';
                for (int k = i - 1; k <= i + 1; k++)
                    for (int l = j - 1; l <= j + 1; l++)
                        if ((k != i || l != j)&&di[k][l]!='*')
                            di[k][l]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << di[i][j];
        cout << endl;
    }
    return 0;
}