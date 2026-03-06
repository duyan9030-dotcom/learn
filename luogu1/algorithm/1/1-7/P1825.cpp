#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, dist;
};
char ma[305][305];
bool vis[305][305];
int n, m;
int sx, sy;                                     // 起点坐标
vector<int> px1(26), py1(26), px2(26), py2(26); // 两个对应传送门坐标
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> ma[i][j];
            char a = ma[i][j];
            if (a == '@')
                sx = i, sy = j;
            if (a >= 'A' && a <= 'Z')
            {
                if (px1[a - 'A'] == 0)
                {
                    px1[a - 'A'] = i;
                    py1[a - 'A'] = j;
                }
                else
                {
                    px2[a - 'A'] = i;
                    py2[a - 'A'] = j;
                }
            }
        }
    queue<node> q;
    q.push({sx, sy, 0});
    vis[sx][sy] = true;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        int level = q.front().dist;
        q.pop();
        if (ma[x][y] == '=')
        {
            cout << level;
            return 0;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            char a = ma[nx][ny];
            if (vis[nx][ny] || nx < 1 || nx > n || ny < 1 || ny > m || a == '#')
                continue;
            vis[nx][ny] = true;
            if (a >= 'A' && a <= 'Z')
                if (nx == px1[a - 'A'] && ny == py1[a - 'A'])
                {
                    nx = px2[a - 'A'];
                    ny = py2[a - 'A'];
                }
                else
                {
                    nx = px1[a - 'A'];
                    ny = py1[a - 'A'];
                }
            q.push({nx, ny, level + 1});
        }
    }
    return 0;
}