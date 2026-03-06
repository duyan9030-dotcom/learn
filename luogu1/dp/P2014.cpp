#include <bits/stdc++.h>
using namespace std;
int head[305];
int nxt[305];
int to[305];
int cnt = 1;
int weight[305];
void addedge(int u, int v, int s)
{
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
    weight[v] = s;
}
int val[305];//
int size[305];//该树节点个数
int dfncnt = 0;
int f(int u)
{
    int i = ++dfncnt;
    val[i] = weight[u];
    size[i] = 1;
    for (int ei = head[u], v; ei > 0;ei=nxt[ei])
        size[i] += f(to[ei]);
    return size[i];
}
int dp[305][305];
int main()
{
    int n, m;
    cin >> n >> m;
    int s, k;
    for (int i = 1; i <= n; i++)
    {
        cin >> k >> s;
        addedge(k, i, s);
    }
    f(0);
    for (int i = n + 1; i >= 2;i--)
    {
        for (int j = 1; j <= m;j++)
        {
            dp[i][j] = max(dp[i + size[i]][j], val[i] + dp[i + 1][j - 1]);
        }
    }
    cout << weight[0] + dp[2][m];
    return 0;
}