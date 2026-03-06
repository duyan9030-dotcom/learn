#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v;
};
const int MAXN = 100001;
const int MAXM = 200001;
int n, m;
edge edgearr[MAXM];
int head[MAXN];
int nxt[MAXM];
int to[MAXM];
int cntg;
int cur[MAXN];
int outdeg[MAXN];
int indeg[MAXN];
int path[MAXM];
int cntp;
bool edgecmp(edge e1, edge e2)
{
    if (e1.u != e2.u)
    {
        return e1.u < e2.u;
    }
    return e1.v < e2.v;
}
void addedge(int u, int v)
{
    nxt[++cntg] = head[u];
    to[cntg] = v;
    head[u] = cntg;
}
void connect()
{
    sort(edgearr + 1, edgearr + m + 1, edgecmp);
    for (int l = 1, r = 1; l <= m; l = ++r)
    {
        while (r + 1 <= m && edgearr[l].u == edgearr[r + 1].u)
            r++;
        for (int i = r, u, v; i >= l; i--)
        {
            u = edgearr[i].u;
            v = edgearr[i].v;
            outdeg[u]++;
            indeg[v]++;
            addedge(u, v);
        }
    }
    for (int i = 1; i <= n; i++)
        cur[i] = head[i];
}
int directedstart()
{
    int start = -1, end = -1;
    for (int i = 1; i <= n; i++)
    {
        int v = outdeg[i] - indeg[i];
        if (v < -1 || v > 1 || (v == 1 && start != -1) || (v == -1 && end != -1))
            return -1;
        if (v == 1)
            start = i;
        if (v == -1)
            end = i;
    }
    if((start==-1)^(end==-1))
        return -1;
    if(start!=-1)
        return start;
    for (int i = 1; i <= n;i++)
    {
        if(outdeg[i]>0)
            return i;
    }
    return -1;
}
void euler(int u)
{
    for (int e = cur[u]; e > 0;e=cur[u])
    {
        cur[u] = nxt[e];
        euler(to[e]);
    }
    path[++cntp] = u;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m;i++)
        cin >> edgearr[i].u >> edgearr[i].v;
    connect();
    int start = directedstart();
    if(start==-1)
        cout << "No\n";
    else{
        euler(start);
        if(cntp!=m+1)
            cout << "No\n";
        else{
            for (int i =cntp; i >= 1;i--)
                cout << path[i] << ' ';
        }
        cout << "\n";
    }
    return 0;
}