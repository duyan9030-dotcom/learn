#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
#define maxn 105
#define maxm 105
    int queue[maxn*maxm][2];
    int l = 0, r = 0;
    bool visited[maxn][maxm];
    int move[5] = {-1, 0, 1, 0, -1};
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int seas = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1)
                {
                    visited[i][j] == true;
                    queue[r][0] = i;
                    queue[r++][1] = j;
                }
                else
                {
                    visited[i][j] = false;
                    seas++;
                }
        if (seas == 0 || seas == n * m)
            return -1;
        int level = 0;
        while (l < r)
        {
            level++;
            int size = r - l;
            for (int k = 0, x, y, nx, ny; k < size; k++)
            {
                x = queue[l][0];
                y = queue[l++][1];
                for (int i = 0; i < 4;i++)
                {
                    nx = x + move[i];
                    ny = y + move[i + 1];
                    if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]==0&&!visited[nx][ny])
                    {
                        visited[nx][ny] = true;
                        queue[r][0] = nx;
                        queue[r++][1] = ny;
                    }
                }
            }
        }
        return level - 1;
    }
};