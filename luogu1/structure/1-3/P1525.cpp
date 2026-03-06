#include <bits/stdc++.h>
using namespace std;
int father[40005];
void build(int n)
{
    for (int i = 1; i <= 2 * n; i++)
        father[i] = i;
}
int find(int x)
{
    if (x != father[x])
        father[x] = find(father[x]);
    return father[x];
}
void unio(int x, int y)
{
    father[find(y)] = find(x);
}
class edge
{
public:
    int a, b;
    int c;
    edge(int ca, int cb, int cc)
    {
        a = ca;
        b = cb;
        c = cc;
    }
    bool operator<(const edge &e2) const
    {
        return c < e2.c;
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    build(n);
    father[n + 1] = n + 1;
    priority_queue<edge> q;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        q.push(edge(a, b, c));
    }
    while (!q.empty())
    {
        edge cur = q.top();
        q.pop();
        if (find(cur.a) == find(cur.b))
        {
            cout << cur.c;
            return 0;
        }
        else
        {
            unio(cur.b + n, cur.a);
            unio(cur.a + n, cur.b);
        }
    }
    cout << 0;
    return 0;
}