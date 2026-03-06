#include <bits/stdc++.h>
using namespace std;
int m, n, a[405], b[25][25], t[25][25], use[21][8005], now[25], lst[25], ans;
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= m * n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> t[i][j];
    for (int i = 1; i <= m * n; ++i)
        for (int id = b[a[i]][++now[a[i]]], w = t[a[i]][now[a[i]]], s = 0, j = lst[a[i]] + 1; s < w; ++j)
        {
            s = (use[id][j] ? 0 : s + 1);
            if (s == w)
            {
                for (int k = j - w + 1; k <= j; k++)
                    use[id][k] = 1;
                ans = max(ans, j);
                lst[a[i]] = j;
            }
        }
    cout << ans;
    return 0;
}
