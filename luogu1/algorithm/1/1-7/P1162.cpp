#include <bits/stdc++.h>
using namespace std;
int n;
int s[35][35];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void dfs1(int x, int y) // 把0改成3
{
    s[x][y] = 3;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && s[nx][ny] == 0)
            dfs1(nx, ny);
    }
}
void dfs2(int x, int y)
{
    s[x][y] = 2;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && s[nx][ny] == 0)
            dfs2(nx, ny);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> s[i][j];
    for (int i = 1; i <= n; i++)
    {
        if (s[1][i] == 0)
            dfs1(1, i);
        if (s[n][i] == 0)
            dfs1(n, i);
        if (s[i][1] == 0)
            dfs1(i, 1);
        if (s[i][n] == 0)
            dfs1(i, n);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][j] == 0)
                dfs2(i, j);
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            cout << (s[i][j] == 3 ? 0 : s[i][j]) << ' ';
    return 0;
}