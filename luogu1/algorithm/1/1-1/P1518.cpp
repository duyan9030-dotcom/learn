#include <bits/stdc++.h>
using namespace std;
char lt[15][15];
char dir[4] = {'n', 'e', 's', 'w'};
bool vis[15][15][15][15][5][5];
bool obstacle(int &x, int &y, int n)
{ // x是行 y是列
    switch (dir[n])
    {
    case 'n':
        if ((x - 1 >= 1) && lt[x - 1][y] != '*')
        {
            x--;
            return true;
        }
        break;
    case 'e':
        if ((y + 1 <= 10) && lt[x][y + 1] != '*')
        {
            y++;
            return true;
        }
        break;
    case 's':
        if ((x + 1 <= 10) && lt[x + 1][y] != '*')
        {
            x++;
            return true;
        }
        break;
    case 'w':
        if ((y - 1 >= 1) && lt[x][y - 1] != '*')
        {
            y--;
            return true;
        }
        break;
    }
    return false;
}
int main()
{
    int fx, fy, cx, cy; // 当前坐标

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            char a;
            cin >> a;
            lt[i][j] = a;
            if (lt[i][j] == 'F')
            {
                fx = i, fy = j;
                lt[i][j] = '.';
            }
            if (lt[i][j] == 'C')
            {
                cx = i, cy = j;
                lt[i][j] = '.';
            }
        }
    int f = 0, c = 0; // 方向
    int m = 0;
    while (!(fx == cx && fy == cy) && m <= 200)
    {
        if (vis[fx][fy][cx][cy][f][c])//如果此时牛和人的位置已经走过则陷入循环，直接出来
        {
            cout << 0;
            return 0;
        }
        vis[fx][fy][cx][cy][f][c] = 1;//标记六维数组此是牛和人的位置已经走过
        if (!obstacle(fx, fy, f))
            f = (f + 1) % 4;
        if (!obstacle(cx, cy, c))
            c = (c + 1) % 4;
        m++;
    }
    cout << m;
    return 0;
}