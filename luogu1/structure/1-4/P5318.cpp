#include <bits/stdc++.h>
using namespace std;
// 链式前向星后进先出类似于栈的特性,想要相邻的点小的先访问需要从大到小建图
int n, m;
int head[100005];
int nexts[1000005];
int to[1000005];
bool visited[100005];
int cnt = 1;
int q[100005];
int l = 0, r = 0;
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
void dfs(int i)
{
    if (visited[i])
        return;
    cout << i << " ";
    visited[i] = true;
    for (int j = head[i]; j > 0; j = nexts[j])
        dfs(to[j]);
}
void bfs(int x)
{
    q[r++] = x;
    visited[x] = true;
    while (l < r)
    {
        int cur = q[l++];
        cout << cur << " ";
        for (int i = head[cur]; i > 0; i = nexts[i])
            if (!visited[to[i]])
            {
                visited[to[i]] = true;
                q[r++] = to[i];
            }
    }
}
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}
int main()
{

    cin >> n >> m;
    vector<pair<int, int>> edge(m);
    for (int i = 0; i < m; i++)
    {
        // int u, v;
        // cin >> u >> v;
        // addedge(u, v);
        cin >> edge[i].first >> edge[i].second;
    }
    sort(edge.begin(), edge.end(), cmp);
    for (int i = 0; i < m; i++)
        addedge(edge[i].first, edge[i].second);
    dfs(1);
    cout << endl;
    memset(visited, false, sizeof(visited));
    bfs(1);
}