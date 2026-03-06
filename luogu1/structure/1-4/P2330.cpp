#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v;
    int w;
};
int father[305];
int find(int i)
{
    if(i!=father[i])
        father[i] = find(father[i]);
    return father[i];
}
void unio(int x,int y)
{
    father[find(x)] = father[y];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    vector<edge> l(m);
    for (int i = 0; i < m; i++)
        cin >> l[i].u >> l[i].v >> l[i].w;
    sort(l.begin(), l.end(), [](edge a, edge b)
         { return a.w < b.w; });
    int edgecnt = 0;
    int me = -1;
    for (int i = 0; i < m;i++)
    {
        if(find(l[i].u)!=find(l[i].v))
        {
            edgecnt++;
            unio(l[i].u, l[i].v);
            me = max(me, l[i].w);
            // cout << l[i].u << " " << l[i].v<<" "
            //      << l[i].w << endl;
        }
        if(edgecnt==n-1)
            break;
    }
    cout << n - 1 << " " << me;
}
