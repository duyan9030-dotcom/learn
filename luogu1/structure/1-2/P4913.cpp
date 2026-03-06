#include <bits/stdc++.h>
using namespace std;
struct node
{
    int value;
    int l, r;//左右孩子下标
};
node tree[100005];
int maxdepth(int root)
{
    return (tree[root].l == 0 && tree[root].r == 0) ? 1 : max(maxdepth(tree[root].l), maxdepth(tree[root].r)) + 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> tree[i].l >> tree[i].r;
    cout << maxdepth(1);
}
