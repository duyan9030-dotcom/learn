//拓扑排序模板
#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int head[maxn];
int nexts[maxn];
int to[maxn];
int indegree[maxn];
int cnt = 1;
void add(int u, int v)
{
    to[cnt] = v;
    nexts[cnt] = head[u];
    head[u] = cnt++;
    indegree[v]++;
}
struct cmp
{
    bool operator()(const int a,const int b)
    {
        return a > b;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    priority_queue<int, vector<int>,cmp> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        cout << cur << " ";
        for (int i = head[cur]; i > 0; i = nexts[i])
        {
            if (--indegree[to[i]] == 0)
                q.push(to[i]);
        }
    }
}