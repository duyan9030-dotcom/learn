#include <bits/stdc++.h>
using namespace std;
struct node
{
    int size;
    // 以当前节点为根的子树中包含的所有元素的总个数。
    int value;
    int cnt;
    node *l;
    node *r;
    node(int v, int c) : value(v), cnt(c), size(c), l(nullptr), r(nullptr) {};
};
node *head = nullptr;
void pushup(node *cur)
{
    if (cur == nullptr)
        return;
    int ls = cur->l ? cur->l->size : 0;
    int rs = cur->r ? cur->r->size : 0;
    cur->size = ls + rs + cur->cnt;
}
int nodesum(node *cur)
{
    return cur ? cur->size : 0;
}
int find(int x, node *cur) // x的排名
{
    if (cur == nullptr)//如果cur为空不存在
        return 0;
    if (x == cur->value)//相等x的排名就是左子树节点数+1
        return nodesum(cur->l);
    else if (x < cur->value)//小于当前值就去左子树上找
        return find(x, cur->l);
    else//大于当前值就去右子树上找
        return find(x, cur->r) + nodesum(cur->l) + cur->cnt;
}
int indexfind(int index, node *cur) // 排名为x的数
{
    int l = nodesum(cur->l);
    if (l >= index)
        return indexfind(index, cur->l);
    if (l + cur->cnt >= index)
        return cur->value;
    return indexfind(index - (l + cur->cnt), cur->r);
}
int pre(int x, node *cur)//树上二分
{
    int res = -2147483647;
    while (cur != nullptr)
        if (cur->value < x)
        {
            res = cur->value;
            cur = cur->r;
        }
        else
            cur = cur->l;
    return res;
}
int next(int x, node *cur)
{
    int res = 2147483647;
    while (cur != nullptr)
        if (cur->value > x)
        {
            res = cur->value;
            cur = cur->l;
        }
        else
            cur = cur->r;
    return res;
}
node *insert(int x, node *cur)
{
    if (cur == nullptr)
        return new node(x, 1);
    if (x > cur->value)
        cur->r = insert(x, cur->r);
    else if (x < cur->value)
        cur->l = insert(x, cur->l);
    else
        cur->cnt++;
    pushup(cur);
    return cur;
}
int main()
{
    int q, op, x;
    cin >> q;
    while (q--)
    {
        cin >> op >> x;
        switch (op)
        {
        case 1:
            cout << find(x, head) + 1 << endl;
            break;
        case 2:
            cout << indexfind(x, head) << endl;
            break;
        case 3:
            cout << pre(x, head) << endl;
            break;
        case 4:
            cout << next(x, head) << endl;
            break;
        case 5:
            head = insert(x, head);
            break;
        }
    }
}