#include <bits/stdc++.h>
using namespace std;
int w;
char ans[1500][1500];
int main()
{
    memset(ans, ' ', sizeof(ans));
    int n;
    cin >> n;
    w = (pow(2, n + 1) - 2) / 2;
    ans[1][w + 1] = '/';
    ans[1][w + 2] = '\\';
    ans[2][w] = '/';
    ans[2][w + 1] = '_';
    ans[2][w + 2] = '_';
    ans[2][w + 3] = '\\';
    w -= 3; // 0
    for (int i = 2; i <= n; i++)
    {
        int k = pow(2, i - 1);               // k==2
        for (int j = k + 1; j <= 2 * k; j++) // 3-4   //左边
        {
            for (int l = w + 1; l <= 2 * k + w; l++) // 5-8
            {
                ans[j][l] = ans[j - k][l + k];
            }
        }
        for (int j = k + 1; j <= 2 * k; j++) // 3-4
        {
            for (int l = 2 * k + w + 1; l <= k * 4 + w; l++) // 9-12
            {
                ans[j][l] = ans[j - k][l - k];
            }
        }
        w -= k * 2;
    }
    for (int i = 1; i <= pow(2, n); i++)
    {
        for (int j = 1; j <= pow(2, n + 1); j++)
            cout << ans[i][j];
        cout << endl;
    }
}
