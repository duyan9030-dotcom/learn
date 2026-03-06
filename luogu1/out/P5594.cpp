#include <bits/stdc++.h>
using namespace std;
bool a[1005][1005];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++)//遍历每个人
    {
        for (int j = 1; j <= m;j++)//每个人的第几天
        {
            int x;
            cin >> x;
            a[x][j] = 1;//在k天和m套模拟题构成的二维数组中修改，
        }
    }
    for (int i = 1; i <= k;i++)
    {
        int ans = 0;
        for (int j = 1; j <= m;j++)//只需将数组各列相加输出即可
        {
            if(a[i][j])
                ans++;
        }
        cout << ans << " ";
        
    }
    return 0;
}