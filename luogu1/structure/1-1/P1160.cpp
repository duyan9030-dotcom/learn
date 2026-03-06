#include <bits/stdc++.h>
using namespace std;
struct node//数组模拟双向链表
{
    int l = 0, r = 0, num;
    bool e = 1;
};
node q[100005];
void add(int k, int p, int i)
{
    if (p == 0)
    {
        q[i].r = k;
        q[i].l = q[k].l;
        q[i].num = i;
        q[q[k].l].r = i;
        q[k].l = i;
        }
    else
    {
        q[i].l = k;
        q[i].r = q[k].r;
        q[i].num = i;
        q[q[k].r].l = i;
        q[k].r = i;
    }
}
int main()
{
    int n;
    cin >> n;
    q[1].num = 1;
    q[1].l = q[1].r = 0;
    for (int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        add(k, p, i);
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int x;
        cin >> x;
        q[x].e = 0;
    }
    int i = 1,k=0;
    while (q[i].l != 0)
        i = q[i].l;
    while(k++!=n)
    {
        if (q[i].e)
            cout << q[i].num << " ";
        i = q[i].r;
    }
}
