#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int c[2005][2005];
int f[2005][2005];
void build(int k)
{
    f[0][0] = 1 % k;
    for (int i = 1; i <= 2000; i++)
    {
        f[i][0] = 1 % k;
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % k;
    }
    for (int i = 1; i <= 2000; i++)
        for (int j = 1; j <= 2000; j++)
            c[i][j] = c[i - 1][j] + c[i][j - 1] - c[i - 1][j - 1] + ((j <= i && f[i][j] == 0) ? 1 : 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, k, n, m;
    cin >> t >> k;
    build(k);
    while (t--)
    {
        cin >> n >> m;
        cout << c[n][min(n, m)] << endl;
    }
    return 0;
}