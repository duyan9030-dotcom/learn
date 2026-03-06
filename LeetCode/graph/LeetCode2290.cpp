#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int move[5] = {-1, 0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        int dis[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dis[i][j] = INT_MAX;
        deque<pair<int, int>> dq;
        dq.push_front({0, 0});
        dis[0][0] = 0;
        while (!dq.empty())
        {
            pair<int, int> p = dq.front();
            dq.pop_front();
            int x = p.first;
            int y = p.second;
            if (x == n - 1 && y == m - 1)
                return dis[x][y];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + move[i], ny = y + move[i + 1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dis[x][y] + grid[nx][ny] < dis[nx][ny])
                {
                    dis[nx][ny] = dis[x][y] + grid[nx][ny];
                    if (grid[nx][ny] == 0)
                        dq.push_front({nx, ny});
                    else
                        dq.push_back({nx, ny});
                }
            }
        }
        return -1;
    }
};
