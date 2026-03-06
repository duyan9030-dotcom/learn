#include <bits/stdc++.h>
using namespace std;
int n, m,ans=0;
char earth[105][105];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y)
{
    earth[x][y] = '.';
    for (int i = 0, nx = x + dx[i], ny = y + dy[i]; i < 8; i++, nx = x + dx[i], ny = y + dy[i])
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && earth[nx][ny] == 'W')
            dfs(nx, ny);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> earth[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (earth[i][j] == 'W')
                dfs(i, j), ans++;
    cout << ans;
}