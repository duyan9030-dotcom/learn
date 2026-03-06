//LCA
//depth 深度
//weigh 宽度

#include <bits/stdc++.h>
using namespace std;
int n, x, y, u, v;
int weigh = 0, level = 0;
struct node
{
    int value;
    int l = 0;
    int r = 0;
};
node tree[105];
void insert(int a, int b)
{
    if (tree[a].l == 0)
        tree[a].l = b;
    else
        tree[a].r = b;
}
int lca(int x, int y, int root)
{
    if (root == 0 || root == x || root == y)
        return root;
    int l = lca(x, y,tree[root].l);
    int r = lca(x, y, tree[root].r);
    if (l != 0 && r != 0)
        return root;
    if (l == 0 && r == 0)
        return 0;
    return l != 0 ? l : r;
}
int depth(int root, int x)
{
    int l = 0;
    queue<node> q;
    q.push(tree[root]);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            node cur = q.front();
            q.pop();
            if (cur.value == x)
                return l;
            if (cur.l != 0)
                q.push(tree[cur.l]);
            if (cur.r != 0)
                q.push(tree[cur.r]);
        }
        l++;
    }
    return l;
}
int dis()
{
    int lcaxy = lca(x, y, 1);
    int xl = depth(1, x) - depth(1, lcaxy);
    int yl = depth(1, y) - depth(1, lcaxy);
    return 2 * xl + yl;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        insert(u, v);
    }
    for (int i = 1; i <= n; i++)
        tree[i].value = i;
    cin >> x >> y;
    queue<node> q;
    q.push(tree[1]);
    while (!q.empty())
    {
        int size = q.size();
        weigh = max(weigh, size);
        for (int i = 0; i < size; i++)
        {
            node cur = q.front();
            q.pop();
            if (cur.l != 0)
                q.push(tree[cur.l]);
            if (cur.r != 0)
                q.push(tree[cur.r]);
        }
        level++;
    }
    cout << level << endl
         << weigh << endl;
    cout << dis();
}