#include <bits/stdc++.h>
using namespace std;
struct node
{
    int x, y, time;
};
int m,x,y,t;
int sf[305][305];
bool v[305][305];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main()
{
    memset(sf, 0x3f, sizeof(sf));
    cin >> m;
    for (int i = 0; i < m;i++)
    {
        cin >> x >> y >> t;
        sf[x][y] = min(sf[x][y], t);
        for (int j = 0; j < 4;j++)
        {
            int nx = x + dx[j], ny = y + dy[j];
            if(nx>=0&&ny>=0)
                sf[nx][ny] = min(sf[nx][ny], t);
        }
    }
    if(sf[0][0]==0)
    {
        cout << -1;
        return 0;
    }
    queue<node> q;
    q.push({0, 0, 0});
    v[0][0] = true;
    while(!q.empty())
    {
        node cur = q.front();
        q.pop();
        if(sf[cur.x][cur.y]>1000)
        {
            cout << cur.time;
            return 0;
        }
        for (int i = 0; i < 4;i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx>=0&&ny>=0&&!v[nx][ny]&&cur.time+1<sf[nx][ny])
            {
                v[nx][ny] = true;
                q.push({nx, ny, cur.time + 1});
            }
        }
    }
    cout << -1;
    return 0;
}