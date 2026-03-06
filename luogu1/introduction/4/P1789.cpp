#include <bits/stdc++.h>
using namespace std;
bool f[110][110] = {0};
//需要考虑越界
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int x, y, o, p;
    for (int i = 2; i <= m + 1; i++)
    {
        cin >> x >> y;
        x += 2, y += 2;
        for (int j = x-1 ; j <= x + 1; j++)
        {
            for (int k = y-1 ; k <= y + 1; k++)
            {
                f[j][k] = 1;
            }
        }
            f[x][y + 2] = 1;
            f[x][y - 2] = 1;
            f[x + 2][y] = 1;
            f[x - 2][y] = 1;
    }
    for (int i = m + 2; i <= m + k + 1; i++)
    {
        cin >> o >> p;
        o += 2, p += 2;
        for (int j = o - 2; j <= o + 2;j++)
        {
            for (int k = p - 2; k <= p + 2;k++)
            {
                f[j][k] = 1;
            }
        }

    }
    int sum = 0;
    for (int i = 3; i <= n+2;i++)
    {
        for (int j = 3; j <= n+2;j++)
        {
            if(f[i][j]==0)
                sum++;
        }
    }
    cout << sum;
    return 0;
}