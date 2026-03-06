#include <bits/stdc++.h>
using namespace std;
int maxwaynode[100005]; // 从第i个点出发所能到达的最大点编号
int head[100005];
int nexts[100005];
int to[100005];
int cnt = 1;
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
void A(int u,int target)
{
    if(maxwaynode[u])
        return;
    maxwaynode[u] = target;
    for (int i = head[u]; i > 0;i=nexts[i])
        A(to[i], target);
    return;
}
int main()
{
    int n, m, u, v;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        addedge(v,u);
    }
    for (int i = n; i>=1; i--)
        A(i, i);
    for (int i = 1; i <= n; i++)
        cout << maxwaynode[i]<<" ";
    return 0;
}