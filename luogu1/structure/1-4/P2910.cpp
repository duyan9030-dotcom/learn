//floyd
#include <bits/stdc++.h>
using namespace std;
int d[105][105];
void build()
{
    for (int i = 0; i < 105;i++)
        for (int j = 0; j < 105; j++)
            d[i][j] = INT_MAX;
}

int main()
{
    build();
    int n, m;
    cin >> n >> m;
    vector<int> a(m+1);
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
    for (int bridge = 1; bridge <= n;bridge++)
    {
        for (int i = 1; i <= n;i++)
        {
            for (int j = 1; j <= n;j++)
            {
                if (d[i][bridge]!=INT_MAX&& d[bridge][j]!=INT_MAX &&d[i][j] > d[i][bridge] + d[bridge][j])
                    d[i][j] = d[i][bridge] + d[bridge][j];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < m;i++)
        ans += d[a[i]][a[i + 1]];
    cout << ans;
}
