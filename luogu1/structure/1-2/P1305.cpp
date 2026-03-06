#include <bits/stdc++.h>
using namespace std;
struct node
{
    char a;
    int l, r;
};
node tree[100];
void houxu(int root)
{
    if (root == 0)
        return;
    cout << tree[root].a;
    houxu(tree[root].l);
    houxu(tree[root].r);
}
int main()
{
    int n, root;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char x, y, z;
        cin >> z >> x >> y;
        if (i == 1)
            root = z - 'a' + 1;
        tree[z - 'a' + 1].a = z;
        tree[z - 'a' + 1].l = x != '*' ? x - 'a' + 1 : 0;
        tree[z - 'a' + 1].r = y != '*' ? y - 'a' + 1 : 0;
    }
    houxu(root);
}