#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n, ans = 0;
bool dp[100000];
void f(int n, int k) //
{
    if (n == 0)
    {
        dp[k] = true;
        return;
    }
    for (int i = 1; i <= n; i++) // 枚举平行的直线
        f(n - i, i * (n - i) + k);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    f(n, 0);
    for (int i = 0; i <= n * (n - 1) / 2; i++)
        if (dp[i])
            ans++;
    cout << ans;
}
