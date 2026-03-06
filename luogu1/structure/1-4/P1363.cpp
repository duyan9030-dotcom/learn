#include <bits/stdc++.h>
using namespace std;
char loca[1505][1505];
bool s = false;
int n, m;
int vis[1505][1505][3];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y, int lx, int ly)
{
    if (s)
        return;
    if (vis[x][y][0])
    {
        if (vis[x][y][1] != lx || vis[x][y][2] != ly)
            s = true;
        return;
    }
    vis[x][y][0] = 1;
    vis[x][y][1] = lx;
    vis[x][y][2] = ly;
    for (int i = 0; i < 4; i++)
    {
        int nlx = lx + dx[i];
        int nly = ly + dy[i];
        int nx = (nlx % n + n) % n;
        int ny = (nly % m + m) % m;
        if (loca[nx][ny] != '#')
            dfs(nx, ny, nlx, nly);
    }
}
int main()
{
    while (cin >> n >> m)
    {
        s = false;
        memset(vis, 0, sizeof(vis));
        int sx, sy;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                cin >> loca[i][j];
                if (loca[i][j] == 'S')
                    sx = i, sy = j;
            }
        dfs(sx, sy, sx, sy);
        if (s)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}