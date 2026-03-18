#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1e9 + 7;
    int dp[505][55][2];
    int nexts[55];
    void clear(int n, int m)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                dp[i][j][0]=dp[i][j][1] = -1;
    }
    void buildnexts(string &s, int m)
    {
        nexts[0] = -1;
        nexts[1] = 0;
        int i = 2, cn = 0;
        while (i < m)
            if (s[i - 1] == s[cn])
                nexts[i++] = ++cn;
            else if (cn > 0)
                cn = nexts[cn];
            else
                nexts[i++] = 0;
    }
    int kmp(string &s, string &e, int n, int m)
    {
        int x = 0, y = 0;
        while (x < n && y < m)
            if (s[x] == e[y])
                x++, y++;
            else if (y == 0)
                x++;
            else
                y = nexts[y];
        return y == m ? x - y : -1;
    }
    int jump(char t, string &e, int j)
    {
        while (j >= 0 && t != e[j])
            j = nexts[j];
        return j;
    }
    int f(string &s, string &e, int n, int m, int i, int j, int free)
    {
        if (j == m)
            return 0;
        if (i == n)
            return 1;
        if (dp[i][j][free] != -1)
            return dp[i][j][free];
        char cur = s[i];
        int ans = 0;
        if (free == 0)
        {
            for (char t = 'a'; t < cur; t++)
                ans = (ans + f(s, e, n, m, i + 1, jump(t, e, j) + 1, 1)) % mod;
            ans = (ans + f(s, e, n, m, i + 1, jump(cur, e, j) + 1, 0)) % mod;
        }
        else
            for (char t = 'a'; t <= 'z'; t++)
                ans = (ans + f(s, e, n, m, i + 1, jump(t, e, j) + 1, 1)) % mod;
        dp[i][j][free] = ans;
        return ans;
    }

    int findGoodStrings(int n, string s1, string s2, string evil)
    {
        int m = evil.size();
        buildnexts(evil, m);
        clear(n, m);
        long long ans = f(s2, evil, n, m, 0, 0, 0)%mod;
        clear(n, m);
        ans = (ans - f(s1, evil, n, m, 0, 0, 0) + mod) % mod;
        if (kmp(s1, evil, n, m) == -1)
            ans = (ans + 1) % mod;
        return ans;
    }
};