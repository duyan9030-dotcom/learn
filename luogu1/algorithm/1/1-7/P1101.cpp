#include <bits/stdc++.h>
using namespace std;
int n;
char ma[105][105];
int vis[105][105];
string s = "yizhong";
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool check(int x, int y, int d)
{
    int nx = x, ny = y;
    for (int i = 0; i < 7; i++, nx += dx[d], ny += dy[d])
        if (nx < 1 || nx > n || ny < 1 || ny > n || ma[nx][ny] != s[i])
            return false;
    return true;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> ma[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ma[i][j] == 'y')
                for (int k = 0; k < 8; k++)
                    if (check(i, j, k))
                        for (int l = 0; l < 7; l++)
                            vis[i + dx[k] * l][j + dy[k] * l] = 1;
    for (int i = 1; i <= n; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            cout << (vis[i][j] ? ma[i][j] : '*');
    return 0;
}