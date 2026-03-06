#include <bits/stdc++.h>
using namespace std;
const int maxn = 30;
int graph[maxn][maxn];
int dp[1 << maxn][maxn];
int n;
int f(int s, int i)
{
    if (s == (1 << n) - 1)
        return graph[i][0];
    if (dp[s][i] != -1)
        return dp[s][i];
    int ans = INT_MAX;
    for (int j = 0; j < n; j++)
        if ((s & (1 << j)) == 0)
            ans = min(ans, graph[i][j] + f(s | (1 << j), j));
    dp[s][i] = ans;
    return ans;
}
int main()
{
    cin >> n;
    for (int s = 0; s < (1 << n); s++)
        for (int i = 0; i < n; i++)
            dp[s][i] = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    cout << f(1, 0);
}