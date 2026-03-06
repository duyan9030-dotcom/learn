#include <bits/stdc++.h>
using namespace std;
int jz[505][505];
void spin(int x, int y, int r, int z)
{
    int zz[2 * r + 1][2 * r + 1];
    if (z == 1)
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                zz[i][j] = jz[x - r + j][y - r + 2 * r - i];
    // 逆时针
    else
        for (int i = 0; i < 2 * r + 1; i++)
            for (int j = 0; j < 2 * r + 1; j++)
                zz[i][j] = jz[x - r + 2 * r - j][y - r + i];
    // 顺时针
    for (int i = x - r; i <= x + r; i++)
        for (int j = y - r; j <= y + r; j++)
            jz[i][j] = zz[i - x + r][j - y + r];
}
int main()
{
    int n, m,l=1;
    cin >> n >> m;
    memset(jz, 0, sizeof(jz));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            jz[i][j] = l++;
    for (int i = 0; i < m; i++)
    {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        spin(x, y, r, z);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << jz[i][j] << " ";
        cout << endl;
    }
    return 0;
}
