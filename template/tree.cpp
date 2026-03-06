#include <bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    node *l;
    node *r;
};
// 层序遍历
#define maxn 10000
node *q[maxn]; 
int l = 0, r = 0;
void f(node *root)
{
    if (root != nullptr)
    {
        l = r = 0;
        q[r++] = root;
        while (l < r)
        {
            int size = r - l;
            for (int i = 0; i < size; i++)
            {
                node *cur = q[l++];
                // 使用的逻辑
                cout << cur->value << " ";
                if (cur->l != nullptr)
                    q[r++] = cur->l;
                if (cur->r != nullptr)
                    q[r++] = cur->r;
            }
        }
    }
}
// 锯齿遍历
void jc(node *root)
{
    if (root != nullptr)
    {
        l = r = 0;
        q[r++] = root;
        bool dir = 0;
        while (l < r)
        {
            int size = r - l;
            for (int i = dir ? r - 1 : 1, j = dir ? -1 : 1, k = 0; k < size; i += j, k++)
            {
                /*使用逻辑*/
                cout << q[i]->value << " ";
            }
            for (int i = 0; i < size; i++)
            {
                node *cur = q[l++];
                // 使用的逻辑
                /*

                */
                if (cur->l != nullptr)
                    q[r++] = cur->l;
                if (cur->r != nullptr)
                    q[r++] = cur->r;
            }
            dir = !dir;
        }
    }
}
// 最大深度
int maxdepth(node *root)
{
    return root == nullptr ? 0 : max(maxdepth(root->l), maxdepth(root->r)) + 1;
}
// 最小深度
int mindepth(node *root)
{
    if (root == nullptr)
        return 0;
    if (root->l == nullptr && root->r == nullptr)
        return 1;
    int ldeep = INT_MAX;
    int rdeep = INT_MAX;
    if (root->l != nullptr)
        ldeep = mindepth(root->l);
    if (root->r != nullptr)
        rdeep = mindepth(root->r);
    return min(ldeep, rdeep) + 1;
}
// 判断完全二叉树
node q[10000];
int l, r;
bool is(node *root)
{
    if (root == nullptr)
        return true;
    l = r = 0;
    q[r++] = root;
    bool leaf = false;
    while (l < r)
    {
        root = q[l++];
        if (root->l == nullptr && root->r != nullptr || (leaf && (root->l != nullptr || root->r != nullptr)))
            return false;
        if (root->l != nullptr)
            q[r++] = root->l;
        if (root->r != nullptr)
            q[r++] = root->r;
        if (root->l == nullptr || root->r == nullptr)
            leaf = true;
    }
    return true;
}
// 求完全二叉树节点个数，时间复杂度低于O(n)
int m(node *head)
{
    if (head == nullptr)
        return 0;
    return f(head, 1, mostleft(head, 1));
}
int f(node *cur, int level, int h)
{
    if (level == h)
        return 1;
    if (mostleft(cur->r, level + 1) == h)
        return (1 << (h - level)) + f(cur->r, level + 1, h);
    else
        return (1 << (h - level - 1)) + f(cur->l, level + 1, h);
}
int mostleft(node *cur, int level)
{
    while (cur != nullptr)
    {
        level++;
        cur = cur->l;
    }
    return level - 1;
}
// lca问题，两个节点的最近公共祖先
node *lowestCommonAncestor(node *root, node *p, node *q)
{
    if(root==nullptr||p==nullptr||q==nullptr)
        return root;
    node *l = lowestCommonAncestor(root->l, p, q);
    node *r = lowestCommonAncestor(root->r, p, q);
    if(l!=nullptr&&r!=nullptr)
        return root;
    if(l==nullptr&&r==nullptr)
        return nullptr;
    return l != nullptr ? l : r;
}
//搜索二叉树上寻找最近公共祖先
node *lowestCommonAncestor2(node *root, node *p, node *q)
{
    while(root->value!=p->value&&root->value!=q->value)
    {
        if(min(p->value,q->value)<root->value&&root->value<max(p->value,q->value))
            break;
        root = root->value < min(p->value, q->value) ? root->r : root->l;
    }
    return root;
}
//路径和为aim的数量
int aim = 3;

