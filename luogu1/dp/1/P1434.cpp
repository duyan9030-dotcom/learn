#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int dp[105][105];
int h[105][105];
int r, c;
int ans = -1;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int dfs(int i, int j, int len)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    dp[i][j] = len;
    for (int k = 0; k <= 3; k++)
    {
        int cx = i + dx[k];
        int cy = j + dy[k];
        if (h[cx][cy] < h[i][j])
        {
            dp[i][j] = max(dp[i][j], dfs(cx, cy, len) + 1);
        }
    }
    return dp[i][j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            cin >> h[i][j], dp[i][j] = -1;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            ans = max(dfs(i, j, 1), ans);
    cout << ans << endl;
}