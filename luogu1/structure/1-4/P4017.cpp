#include <bits/stdc++.h>
using namespace std;
#define mod 80112002
int head[5005];
int nexts[500005];
int to[500005];
int indegree[5005];
int dp[5005];
int cnt = 1;
void addedge(int u, int v)
{
    to[cnt] = v;
    nexts[cnt] = head[u];
    head[u] = cnt++;
    indegree[v]++;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        addedge(u, v);
    }
    int queue[5005];
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            queue[r++] = i;
            dp[i] = 1;
        }
    }
    int sum = 0;
    while (l < r)
    {
        int cur = queue[l++];
        if (head[cur] == 0)//没有往下走的边了就计数
            sum = (sum + dp[cur]) % mod;
        else
        {
            for (int i = head[cur],v; i > 0;i=nexts[i])//遍历这个点的所有邻居,把把自己的信息推给下一层然后消除自己对邻居的干扰
            {
                v = to[i];
                dp[v] = (dp[v] + dp[cur]) % mod;
                if(--indegree[v]==0)
                    queue[r++] = v;
            }
        }
    }
    cout << sum;
}