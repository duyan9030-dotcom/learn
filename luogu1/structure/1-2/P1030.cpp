#include <bits/stdc++.h>
using namespace std;
struct node
{
    char a;
    int l;
    int r;
};
string s1, s2;
node tree[15];
int cnt = 0;
// l1,r1中序遍历
// l2,r2后序遍历
int f(int l1, int r1, int l2, int r2)
{

    if (l1 > r1)
        return 0;
    int idx = ++cnt;
    tree[idx].a = s2[r2];
    tree[idx].l = tree[idx].r = 0;
    if (l1 == r1)
        return idx;
    int k = s1.find(s2[r2]); // 查找头节点在中序中的下标
    tree[idx].l = f(l1, k - 1, l2, l2 + k - l1 - 1);
    tree[idx].r = f(k + 1, r1, l2 + k - l1, r2 - 1);
    return idx;
}
void xianxu(int root)
{
    if (root == 0)
        return;
    cout << tree[root].a;
    xianxu(tree[root].l);
    xianxu(tree[root].r);
}
int main()
{
    cin >> s1 >> s2;
    f(0, s1.size() - 1, 0, s2.size() - 1);
    xianxu(1);
}