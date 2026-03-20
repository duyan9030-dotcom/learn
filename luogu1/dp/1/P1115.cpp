#include <bits/stdc++.h>
using namespace std;
int n, a, dp; // 以a[i]结尾的最大子段和，分为要前面和不要前面，如果加上前面会使值更大就加
int ans = -1e9;
int main()
{
    cin >> n >> dp;
    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        dp = max(a, a + dp);
        ans = max(ans, dp);
    }
    cout << ans;
    return 0;
}