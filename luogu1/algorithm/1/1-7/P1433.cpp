#include <bits/stdc++.h>
using namespace std;
int n; // 点的个数
double x[20], y[20], ans = 1e18, dis[20][20], memo[1 << 15][15];
double solve(int mask, int now)
{
    if (mask == (1 << n) - 1)
        return 0;
    if (memo[mask][now] > 0)
        return memo[mask][now];
    double res = 1e18;
    for (int i = 0; i < n; i++) // 枚举下一个吃的奶酪
        if (!(mask & (1 << i)))
            res = min(res, dis[now][i] + solve(mask | (1 << i), i));
    return memo[mask][now] = res;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dis[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
        dis[n][i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    }
    printf("%.2lf", solve(0, n));
    return 0;
}
