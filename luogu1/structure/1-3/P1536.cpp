//并查集
#include <bits/stdc++.h>
using namespace std;
int father[1005];
int find(int x)
{
    if (x != father[x])
        father[x] = find(father[x]);
    return father[x];
}
void unio(int a, int b)
{
    father[find(a)] = find(b);
}
void init(int n)
{
    for (int i = 1; i <= n; i++)
        father[i] = i;
}
int main()
{
    while (1)
    {

        int n, m, sum = 1;
        cin >> n;
        if(n==0)
            break;
        cin >> m;
        init(n);
        for (int i = 1; i <= m; i++)
        {
            int a, b;
            cin >> a >> b;
            if (find(a) != find(b))
                sum++;
            unio(a, b);
        }
        cout << n - sum<<endl;
    }
    return 0;
}