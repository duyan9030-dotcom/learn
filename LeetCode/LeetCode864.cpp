#include <bits/stdc++.h>
using namespace std;
//分层最短路
class Solution
{
public:
    int move[5] = {-1, 0, 1, 0, -1};
    vector<vector<char>> grid{31};
    bool vis[31][31][1 << 6] = {false};
    int q[31 * 31 * (1 << 6)][3];
    int l, r, n, m, key;
    void build(vector<string> &g)
    {
        l = r = key = 0;
        n = g.size();
        m = g[0].size();
        for (int i = 0; i < n; i++)
            for (char a : g[i])
                grid[i].push_back(a);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    vis[i][j][0] = true;
                    q[r][0] = i;
                    q[r][1] = j;
                    q[r++][2] = 0;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                    key |= 1 << (g[i][j] - 'a');
            }
    }
    int shortestPathAllKeys(vector<string> &g)
    {
        build(g);
        int level = 1;
        while (l < r)
        {
            for (int k = 0, size = r - l, x, y, s; k < size; k++)
            {
                x = q[l][0];
                y = q[l][1];
                s = q[l++][2];
                for (int i = 0, nx, ny, ns; i < 4; i++)
                {
                    nx = x + move[i];
                    ny = y + move[i + 1];
                    ns = s;
                    if (nx < 0 || nx == n || ny < 0 || ny == m || grid[nx][ny] == '#')//越界或者走不了
                        continue;
                    if(grid[nx][ny]>='A'&&grid[nx][ny]<='F'&&((ns&(1<<(grid[nx][ny]-'A')))==0))//找到锁但开不了
                        continue;
                    if(grid[nx][ny]>='a'&&grid[nx][ny]<='f')//找到钥匙
                        ns |= (1 << (grid[nx][ny] - 'a'));
                    if(ns==key)//找到所有钥匙
                        return level;  
                    if(!vis[nx][ny][ns])
                    {
                        vis[nx][ny][ns] = true;
                        q[r][0] = nx;
                        q[r][1] = ny;
                        q[r++][2] = ns;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};