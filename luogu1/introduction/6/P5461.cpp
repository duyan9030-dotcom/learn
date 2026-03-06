#include <bits/stdc++.h>
using namespace std;
int k[1025][1025];
void shemian(int l, int x, int y)//x,y记录横纵坐标，l为操作矩阵边长
{
    if (l == 2)//特判 必须有
    {
        k[x][y] = 0;
        return;
    }
    for (int i = x; i < l / 2 + x; i++)
        for (int j = y; j < l / 2 + y; j++)

            k[i][j] = 0;
    shemian(l / 2, x, y + l / 2);
    shemian(l / 2, x + l / 2, y);
    shemian(l / 2, x + l / 2, y + l / 2);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < pow(2, n); i++)
        for (int j = 0; j < pow(2, n); j++)
            k[i][j] = 1;
    shemian(pow(2, n), 0, 0);
    for (int i = 0; i < pow(2, n); i++)
    {
        for (int j = 0; j < pow(2, n); j++)
            cout << k[i][j] << " ";
        cout << endl;
    }
    return 0;
}
