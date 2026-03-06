#include <bits/stdc++.h>
using namespace std;
int ma[10][10];
int n, m, t;
int sx, sy, fx, fy;
int sum = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool vis[10][10];
void dfs(int x, int y)
{
    if (x == fx && y == fy)
    {
        sum++;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && ny >= 1 && nx <= n && ny <= m &&!vis[nx][ny]&& ma[nx][ny] != 1)
        {
            vis[nx][ny] = true;
            dfs(nx, ny);
            vis[nx][ny] = false;
        }
    }
}
int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        ma[x][y] = 1;
    }
    vis[sx][sy] = true;
    dfs(sx, sy);
    cout << sum;
    return 0;
}