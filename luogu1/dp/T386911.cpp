#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int endds[100005];
int dp[100005];
int bs(int len, int num)
{
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (endds[m] <= num)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    int len = 0;
    for (int i = n - 1, find; i >= 0; i--)
    {
        find = bs(len, a[i]);
        if (find == -1)
        {
            endds[len++] = a[i];
            dp[i] = len;
        }
        else
        {
            endds[find] = a[i];
            dp[i] = find + 1;
        }
    }
    vector<int> ans(len, INT_MAX);
    for (int i = 0; i < n; i++)
        if (dp[i] == len)
            ans[0] = a[i];
        else if (ans[len - dp[i] - 1] < a[i])
            ans[len - dp[i]] = a[i];
    for (int x : ans)
        cout << x << " ";
    return 0;
}