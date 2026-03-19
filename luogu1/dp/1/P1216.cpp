#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int a[1005][1005];
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j - 1 < 1)
            {
                a[i][j] += a[i - 1][j];
            }
            else
            {
                a[i][j] += max(a[i - 1][j - 1], a[i - 1][j]);
            }
        }
    }
    int ans = -1;
    for (int j = 1; j <= n;j++)
        ans = max(ans, a[n][j]);
    cout << ans;
}