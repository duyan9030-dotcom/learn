#include <bits/stdc++.h>
using namespace std;
queue<int> q, q1;
int l[405][405];//visit数组如果没有走过就标记为0
int ans[405][405];//步数数组
int dx[8] = {-2, -2, 2, 2, 1, -1, 1, -1};
int dy[8] = {-1, 1, -1, 1, 2, -2, -2, 2};//一共有八种走法
int n, m, x, y;
int main()
{
    memset(ans, -1, sizeof(ans));
    cin >> n >> m >> x >> y;
    q.push(x);
    q1.push(y);
    ans[x][y] = 0;
    l[x][y] = 1;
    while (!q.empty())
    {
        for (int i = 0; i < 8; i++)
        {
            int tx = q.front() + dx[i];
            int ty = q1.front() + dy[i];
            if (tx > 0 && tx <= n && ty > 0 && ty <= m && l[tx][ty] == 0)
            {
                l[tx][ty] = 1;
                ans[tx][ty] = ans[q.front()][q1.front()] + 1;
                q.push(tx);
                q1.push(ty);
            }
        }
        q.pop();
        q1.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}