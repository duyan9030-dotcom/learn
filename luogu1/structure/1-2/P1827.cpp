#include <bits/stdc++.h>
using namespace std;
//前序中序构建树
struct node
{
    char value;
    int l, r; // 左右孩子下标
};
node tree[30];
string s1, s2;
int cnt = 0;
int build(int l1, int r1,int l2, int r2)
{
    if (l1 > r1)
        return 0;
    int idx = ++cnt;
    tree[idx].value = s1[l1];
    tree[idx].l = tree[idx].r = 0;
    if(l1==r1)
        return idx;
    int k = s2.find(s1[l1]);
    tree[idx].l = build(l1 + 1, l1 + k - l2, l2, k - 1);
    tree[idx].r = build(l1 + k - l2 + 1, r1, k + 1, r2);
    return idx;
}
void later(int root)
{
    if (root == 0)
        return;
    later(tree[root].l);
    later(tree[root].r);
    cout << tree[root].value;
}

int main()
{
    cin >> s2 >> s1;
    build(0, s2.size() - 1, 0, s1.size());
    later(1);
}