#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct x
    {
        int i, j;
        int d;
    };
    struct cmp
    {
        bool operator()(const x &a, const x &b)
        {
            return a.d > b.d;
        }
    };
    int move[5] = {-1, 0, 1, 0, -1};
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int dis[55][55];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dis[i][j] = 1e9;
        dis[0][0] = grid[0][0];
        bool vis[55][55] = {false};
        priority_queue<x, vector<x>, cmp> q;
        q.push({0, 0, dis[0][0]});
        while (!q.empty())
        {
            int x = q.top().i;
            int y = q.top().j;
            int w = q.top().d;
            q.pop();
            if (vis[x][y])
                continue;
            vis[x][y] = true;
            if (x == n - 1 && y == m - 1)
                return w;
            for (int i = 0, nx, ny, nw; i < 4; i++)
            {
                nx = x + move[i];
                ny = y + move[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny])
                {
                    nw = max(w, grid[nx][ny]);
                    if (nw < dis[nx][ny])
                    {
                        dis[nx][ny] = nw;
                        q.push({nx, ny, nw});
                    }
                }
            }
        }
        return -1;
    }
};