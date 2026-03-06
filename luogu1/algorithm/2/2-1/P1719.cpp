#include <bits/stdc++.h>
using namespace std;
//二维前缀和 
int sum[125][125];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> sum[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    int m = INT_MIN;
    for (int x1 = 1; x1 <= n; x1++)
        for (int y1 = 1; y1 <= n; y1++)
            for (int x2 = 1; x2 <= n; x2++)
                for (int y2 = 1; y2 <= n; y2++)
                {
                    if (x1 > x2 || y1 > y2)
                        continue;
                    else
                        m = max(m, sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1]);
                }
    cout << m;
}