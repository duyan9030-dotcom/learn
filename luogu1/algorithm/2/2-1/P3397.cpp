#include <bits/stdc++.h>
using namespace std;
//二维差分 二维前缀和
int sum[1005][1005];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        sum[x1][y1] += 1;
        sum[x1][y2 + 1] -= 1;
        sum[x2 + 1][y1] -= 1;
        sum[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] += sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << sum[i][j]<<" ";
        cout << endl;
    }
}