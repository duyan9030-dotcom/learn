#include <bits/stdc++.h>
using namespace std;
int head[6005];
int nxt[6005];
int to[6005];
int cnt = 1;
void addedge(int u, int v)
{
    nxt[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
}
int happy[6005];
int yes[6005];
int no[6005];
void f(int u)
{
    no[u] = 0;
    yes[u] = happy[u];
    for (int ei = head[u], v; ei > 0;ei=nxt[ei])
    {
        v = to[ei];
        f(v);
        no[u] += max(no[v], yes[v]);
        yes[u] += no[v];
    }
}
int main()
{
    int n, u, v, h;
    cin >> n;
    vector<bool> boss(n + 1, true);
    for (int i = 1; i <= n; i++)
        cin >> happy[i];
    for (int i = 1; i < n; i++)
    {
        cin >> v >> u;
        addedge(u, v);
        boss[v] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        if (boss[i])
        {
            h = i;
            break;
        }
    }
    f(h);
    cout << max(no[h], yes[h]);
}