// 分层最短路
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, use, cost;
    bool operator>(const node &other) const
    {
        return cost > other.cost;
    }
};
int head[20005];
int nexts[100005];
int to[100005];
int cnt = 1;
int weight[100005];
int n, m, k, u, v, w, s, t;
int dis[20005][11];
bool vis[20005][11];
// 0：到达的城市编号
// 1：已经使用的免单次数
// 2：沿途的花费
priority_queue<node, vector<node>, greater<node>> q;
void addedge(int u, int v, int w)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}
void build()
{
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> k >> s >> t;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        addedge(u, v, w);
        addedge(v, u, w);
    }
}
int dj()
{
    dis[s][0] = 0;
    q.push({s, 0, 0});
    while (!q.empty())
    {
        int u = q.top().u;
        int use = q.top().use;
        int cost = q.top().cost;
        q.pop();
        if (vis[u][use])
            continue;
        if (u == t)
            return cost;
        for (int i = head[u], v, w; i > 0; i = nexts[i])
        {
            v = to[i];
            w = weight[i];
            if (use < k && dis[v][use + 1] > dis[u][use])
            {
                dis[v][use + 1] = dis[u][use];
                q.push({v, use + 1, dis[v][use + 1]});
            }
            if (dis[v][use] > dis[u][use] + w)
            {
                dis[v][use] = dis[u][use] + w;
                q.push({v, use, dis[v][use]});
            }
        }
    }
    return -1;
}
int main()
{
    build();
    cout << dj();
}