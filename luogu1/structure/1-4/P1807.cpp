#include <bits/stdc++.h>
using namespace std;
int head[1505], indegree[1505], nexts[50005], to[50005], weigh[50005];
int cnt = 1, n, m, l = 0, r = 0;
int dp[1505]; // dp[i]为1到i的最长距离
int q[1505];
void addedge(int u, int v, int w)
{
    indegree[v]++;
    weigh[cnt] = w;
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
int main()
{
    //memset(dp, -1e9, sizeof(dp));
    fill(dp, dp + 1505, -1e9);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q[r++] = i;
    dp[1] = 0;
    while (l < r)
    {
        int cur = q[l++];
        for (int i = head[cur]; i > 0; i = nexts[i])
        {
            if (dp[cur] >-1e9)
                dp[to[i]] = max(dp[to[i]], dp[cur] + weigh[i]);
            if(--indegree[to[i]]==0)
                q[r++] = to[i];
        }
    }
    cout << (dp[n]==-1e9?-1:dp[n]);
    return 0;

}