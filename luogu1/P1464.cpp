#include <bits/stdc++.h>
using namespace std;
int w[25][25][25];
bool vis[25][25][25];
int h(long long a, long long b, long long c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return h(20, 20, 20);
    if(vis[a][b][c])
        return w[a][b][c];
    if (a < b && b < c)
        w[a][b][c] = h(a, b, c - 1) + h(a, b - 1, c - 1) - h(a, b - 1, c);
    else
        w[a][b][c] = h(a - 1, b, c) + h(a - 1, b - 1, c) + h(a - 1, b, c - 1) - h(a - 1, b - 1, c - 1);
    vis[a][b][c] = true;
    return w[a][b][c];
}
int main()
{
    long long a, b, c;
    memset(vis, false, sizeof(vis));
    cin >> a >> b >> c;
    while(a!=-1||b!=-1||c!=-1)
    {
        cout << "w(" << a << "," << b << "," << c << ")" << h(a, b, c);
        cin >> a >> b >> c;
    }
    return 0;
}