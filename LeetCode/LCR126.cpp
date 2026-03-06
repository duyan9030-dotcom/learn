#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
class Solution
{
public:
    vector<vector<int>> multi(vector<vector<int>> &a, vector<vector<int>> &b) // a[0].size()必须等于b.size();
    {
        int n = a.size();
        int m = b[0].size();
        int k = a[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int c = 0; c < k; c++)
                    ans[i][j] = (ans[i][j] + (1LL * a[i][c] * b[c][j]) % mod) % mod;
        return ans;
    }
    vector<vector<int>> power(vector<vector<int>> &a, int p)
    {
        int n = a.size();
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            ans[i][i] = 1;
        while (p != 0)
        {
            if (p & 1)
                ans = multi(ans, a);
            a = multi(a, a);
            p >>= 1;
        }
        return ans;
    }
    int fib(int n)
    {
        if (n < 2)
            return n;
        vector<vector<int>> k = {{1, 1}, {1, 0}};
        vector<vector<int>> a = {{1, 0}};
        k = power(k, n - 1);
        vector<vector<int>> ans = multi(a, k);
        return ans[0][0];
    }
};