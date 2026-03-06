#include <bits/stdc++.h>
using namespace std;
int father[2005];
int find(int a)
{
    if (a != father[a])
        father[a] = find(father[a]);
    return father[a];
}
void unio(int a, int b)
{
    father[find(b)] = find(a);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 2 * n; i++)
        father[i] = i;
    for (int i = 0; i < m; i++)
    {
        char a;
        cin >> a;
        int p, q;
        cin >> p >> q;
        if (a == 'E')
        {
            unio(p, q + n);
            unio(q, p + n);
        }
        else
        {
            unio(p, q);
        }
    }
    for (int i = 1; i <= n;i++)
        cout << father[i] << ' ';
    cout << endl;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (father[i] == i)
            ans++;
    cout << ans;
}