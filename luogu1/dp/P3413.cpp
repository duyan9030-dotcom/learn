#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1001;
int dp[maxn][11][11][2];
void build(int n)
{
    for (int a = 0; a < n; a++)
        for (int b = 0; b <= 10; b++)
            for (int c = 0; c <= 10; c++)
                for (int d = 0; d <= 1; d++)
                    dp[a][b][c][d] = -1;
}
bool check(string l)
{
    for (int i = 1; i < l.size(); i++)
    {
        if (l[i] == l[i - 1])
            return true;
        if (i >= 2 && l[i] == l[i - 2])
            return true;
    }

    return false;
}
int f(string &s, int i, int pp, int p, int free)
{
    if (i == s.size())
        return 1;
    if (dp[i][pp][p][free] != -1)
        return dp[i][pp][p][free];
    int ans = 0;
    if (free == 0)
    {
        if (p == 10)
        {
            ans = (ans + f(s, i + 1, 10, 10, 1)) % mod;
            for (int cur = 1; cur < s[i] - '0'; cur++)
                ans = (ans + f(s, i + 1, p, cur, 1)) % mod;
            ans = (ans + f(s, i + 1, p, s[i] - '0', 0)) % mod;
        }
        else
        {
            for (int cur = 0; cur < s[i] - '0'; cur++)
                if (pp != cur && p != cur)
                    ans = (ans + f(s, i + 1, p, cur, 1)) % mod;
            if (pp != s[i] - '0' && p != s[i] - '0')
                ans = (ans + f(s, i + 1, p, s[i] - '0', 0)) % mod;
        }
    }
    else
    {
        if (p == 10)
        {
            ans = (ans + f(s, i + 1, 10, 10, 1)) % mod;
            for (int cur = 1; cur <= 9; cur++)
                ans = (ans + f(s, i + 1, p, cur, 1)) % mod;
        }
        else
        {
            for (int cur = 0; cur <= 9; cur++)
                if (pp != cur && p != cur)
                    ans = (ans + f(s, i + 1, p, cur, 1)) % mod;
        }
    }
    dp[i][pp][p][free] = ans;
    return ans;
}
int cnt(string &s)
{
    if (s[0] == '0')
        return 0;
    int n = s.size();
    long long all = 0;
    long long base = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        all = (all + base * (s[i] - '0')) % mod;
        base = (base * 10) % mod;
    }
    build(n);
    return ((all - f(s, 0, 10, 10, 0) + mod)) % mod;
}
int main()
{
    string l, r;
    cin >> l >> r;
    int ans = (cnt(r) - cnt(l) + mod) % mod;
    if (check(l))
        ans = (ans + 1) % mod;
    cout << ans;
}