// dijkstra+unidex
#include <bits/stdc++.h>
using namespace std;
#define maxsizen 100005
#define maxsizem 200005
int n, m, s;
// 反向索引堆
int heap[maxsizen];
int where[maxsizen];
int heapsize = 0;
// 链式前向星
int head[maxsizen];
int nexts[maxsizem];
int to[maxsizem];
int cnt = 1;
int weigh[maxsizem];
// 最短距离
int dis[maxsizen];
void swap(int a, int b)
{
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
    where[heap[a]] = a;
    where[heap[b]] = b;
}
void heapinsert(int i)
{
    while (dis[heap[i]] < dis[heap[(i - 1) / 2]])
    {
        swap(i, (i - 1) / 2);
        i = (i - 1) / 2;
    }
}
void heapify(int i)
{
    int l = 2 * i + 1;
    while (l < heapsize)
    {
        int best = (l + 1 < heapsize && dis[heap[l + 1]] < dis[heap[l]]) ? l + 1 : l;
        best = dis[heap[best]] < dis[heap[i]] ? best : i;
        if (best == i)
            break;
        swap(best, i);
        i = best;
        l = i * 2 + 1;
    }
}
int pop()
{
    int ans = heap[0];
    swap(0, --heapsize);
    heapify(0);
    where[ans] = -2;
    return ans;
}
void addorupdateorignore(int u, int d)
{
    if (where[u] == -1)
    {
        heap[heapsize] = u;
        where[u] = heapsize++;
        dis[u] = d;
        heapinsert(where[u]);
    }
    else
    {
        dis[u] = min(dis[u], d);
        heapinsert(where[u]);
    }
}
void addedge(int u, int v, int w)
{
    weigh[cnt] = w;
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
void build()
{
    fill(where, where + maxsizen, -1);
    fill(dis, dis + maxsizen, 1e9);
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addedge(u, v, w);
    }
}
// dijkstra+普通堆
// int dis[maxsizen];
// int vis[maxsizen];
// int head[maxsizen];
// int nexts[maxsizem];
// int to[maxsizem];
// int cnt = 1;
// int weigh[maxsizem];
// int n, m, s, u, v, w;
// struct node
// {
//     int u;
//     int d;
//     bool operator>(const node &other) const
//     {
//         return d > other.d;
//     }
// };
// priority_queue<node, vector<node>, greater<node>> q;
// void addedge(int u, int v, int w)
// {
//     weigh[cnt] = w;
//     nexts[cnt] = head[u];
//     to[cnt] = v;
//     head[u] = cnt++;
// }
// void build()
// {
//     fill(dis, dis + maxsizen, 1e9);
//     cin >> n >> m >> s;
//     for (int i = 0; i < m; i++)
//     {
//         cin >> u >> v >> w;
//         addedge(u, v, w);

//     }
// }
// void m1()
// {
//     build();
//     q.push({s, 0});
//     dis[s] = 0;
//     while (!q.empty())
//     {
//         int u = q.top().u;
//         q.pop();
//         if (vis[u])
//             continue;
//         vis[u] = true;
//         for (int i = head[u]; i > 0; i = nexts[i])
//         {
//             int v = to[i];
//             int w = weigh[i];
//             if (!vis[v] && dis[u] + w < dis[v])
//             {
//                 dis[v] = dis[u] + w;
//                 q.push({v, dis[v]});
//             }
//         }
//     }
//     for (int i = 1; i <= n; i++)
//         cout << dis[i] << " ";
// }
void m2()
{
     build();
     addorupdateorignore(s, 0);
     while (heapsize)
     {
         int u = pop();
         for (int i = head[u]; i > 0; i = nexts[i])
             addorupdateorignore(to[i], dis[u] + weigh[i]);
     }
     for (int i = 1; i <= n; i++)
         cout << dis[i] << " ";
}
int main()
{
    // dj+反向索引堆
    m2();
    //  dijkstra+普通堆
    //m1();
    return 0;
}