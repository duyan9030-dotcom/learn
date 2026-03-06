#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // m : 帽子颜色的最大值, 1 ~ m
    // n : 人的数量，0 ~ n-1
    // i : 来到了什么颜色的帽子
    // s : n个人，谁没满足状态就是0，谁满足了状态就是1
    // dp : 记忆化搜索的表
    // 返回 : 有多少种方法
    int mod = 1000000007;
    int f(vector<int> &hats, int m, int n, int i, int s, vector<vector<int>> &dp)
    {
        if (s == (1 << n) - 1)
            return 1;
        if (i == m + 1)
            return 0;
        if (dp[i][s] != -1)
            return dp[i][s];
        int ans = f(hats, m, n, i + 1, s, dp);
        int cur = hats[i];
        // for (int p = 0; p < n; p++)
        //hats[i]帽子可以满足这个人并且这个人没有被满足
        //     if ((cur & (1 << p)) != 0 && (s & (1 << p)) == 0)
        //         ans = (ans + f(hats, m, n, i + 1, s | (1 << p), dp)) % mod;
        int rightone;
        while(cur!=0)
        {
            rightone = cur & -cur;
            if((s&rightone)==0)
                ans = (ans + f(hats, m, n, i + 1, s | rightone, dp)) % mod;
            cur ^= rightone;
        }
        dp[i][s] = ans;
        return ans;
    }
    int numberWays(vector<vector<int>> &arr)
    {
        // 帽子颜色的最大值
        int m = 0;
        for (auto hat : arr)
            for (auto p : hat)
                m = max(m, p);
        int n = arr.size();
        // 1 ~ m 帽子，能满足哪些人，状态信息 -> int
        vector<int> hats(m + 1);
        for (int i = 0; i < n; i++)
            for (int hat : arr[i])
                hats[hat] |= 1 << i;
        vector<vector<int>> dp(m + 1, vector<int>(1 << n, -1));
        return f(hats, m, n, 1, 0, dp);
    }
};