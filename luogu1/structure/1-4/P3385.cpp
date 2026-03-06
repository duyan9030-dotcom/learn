//Bellman-Ford+SPFA
//求负环
#include <bits/stdc++.h>
using namespace std;
int head[2005];
int nexts[6005];
int to[6005];
int weight[6005];
int cnt = 1;
int q[4000005];
int l, r;
bool enter[2005];
int dis[2005];
int updatecnt[2005];
void addedge(int u, int v, int w)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    weight[cnt] = w;
    head[u] = cnt++;
}
void build(int n)
{
    cnt = 1;
    l = r = 0;
    fill(head, head + n + 1, 0);
    fill(enter, enter + n + 1, false);
    fill(dis, dis + n + 1, INT_MAX);
    fill(updatecnt, updatecnt + n + 1, 0);
}
bool spfa(int n)
{
    dis[1] = 0;
    updatecnt[1]++;
    q[r++] = 1;
    enter[1] = true;
    while (l < r)
    {
        int u = q[l++];
        enter[u] = false;
        for (int ei = head[u], v, w; ei > 0; ei = nexts[ei])
        {
            v = to[ei];
            w = weight[ei];
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!enter[v])
                {
                    if (updatecnt[v]++ == n)
                        return true;
                    q[r++] = v;
                    enter[v] = true;
                }
            }
        }
    }
    return false;
}
void solve()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    build(n);
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        if (w >= 0)
        {
            addedge(u, v, w);
            addedge(v, u, w);
        }

        else
            addedge(u, v, w);
    }
    cout << (spfa(n) ? "YES" : "NO") << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}