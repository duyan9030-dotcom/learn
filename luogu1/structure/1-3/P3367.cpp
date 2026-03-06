#include <bits/stdc++.h>
using namespace std;
int father[1000001];
int size[1000001];
int stacks[1000001];
int find(int i)
{
    int size = 0;
    while (i != father[i])
    {
        stacks[size++] = i;
        i = father[i];
    }
    while (size > 0) // 扁平化路径压缩
        father[stacks[--size]] = i;
    return i;
}
int find2(int i)
{
    if (i != father[i])
        father[i] = find2(father[i]);
    return father[i];
}
bool issamset(int a, int b)
{
    return find2(a) == find2(b);
}
void unio1(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa != fb)
    {
        if (size[fa] >= size[fb]) // 小挂大
        {
            size[fa] += size[fb];
            father[fb] = fa;
        }
        else
        {
            size[fb] += size[fa];
            father[fa] = fb;
        }
    }
}
void unio2(int a, int b)
{
    father[find(a)] = find(b);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        father[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)
            unio1(x, y);
        else
        {
            if (issamset(x, y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
}