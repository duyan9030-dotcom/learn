#include <bits/stdc++.h>
using namespace std;
int head[1005];
int nexts[10005];
int to[10005];
int cnt = 1;
int cow[105];
bool arr[105][1005];
// 第i个奶牛能到达第j个牧场吗
bool visited[1005];
int k, n, m;
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
void dfs(int location, int num) // location:num号奶牛可以到在location号牧场
{
    if (visited[location])
        return;
    arr[num][location] = true;
    visited[location] = true;
    for (int ei = head[location]; ei > 0; ei = nexts[ei]) // 遍历所有边
    {
        dfs(to[ei], num);
    }
}
int main()
{
    cin >> k >> n >> m;
    for (int i = 1; i <= k; i++)
        cin >> cow[i];
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        addedge(u, v);
    }
    int sum = 0;
    for (int i = 1; i <= k; i++) // 遍历每个奶牛能到达的牧场设为1
    {
        fill(visited, visited + n + 1, false);
        dfs(cow[i], i);
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = false;
        for (int j = 1; j <= k; j++)
        {
            if (!arr[j][i])
                break;
            if (j == k)
                flag = true;
        }
        if (flag)
            sum++;
    }
    cout << sum;
    return 0;
}