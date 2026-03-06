#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    const int maxv = 30;
    const int limit = 1 << 10;
    const int mod = 1000000007;
    int own[31] = {
        0b0000000000, // 0
        0b0000000000, // 1
        0b0000000001, // 2
        0b0000000010, // 3
        0b0000000000, // 4
        0b0000000100, // 5
        0b0000000011, // 6
        0b0000001000, // 7
        0b0000000000, // 8
        0b0000000000, // 9
        0b0000000101, // 10
        0b0000010000, // 11
        0b0000000000, // 12
        0b0000100000, // 13
        0b0000001001, // 14
        0b0000000110, // 15
        0b0000000000, // 16
        0b0001000000, // 17
        0b0000000000, // 18
        0b0010000000, // 19
        0b0000000000, // 20
        0b0000001010, // 21
        0b0000010001, // 22
        0b0100000000, // 23
        0b0000000000, // 24
        0b0000000000, // 25
        0b0000100001, // 26
        0b0000000000, // 27
        0b0000000000, // 28
        0b1000000000, // 29
        0b0000000111  // 30
    };
    int f(int i, int s, vector<int> &cnt, vector<vector<int>> &dp)
    {
        if (dp[i][s] != -1)
            return dp[i][s];
        int ans = 0;
        if (i == 1)
        {
            if (s == 0)
            {
                ans = 1;
                for (int j = 0; j < cnt[1]; j++)
                    ans = (ans << 1) % mod;
            }
        }
        else
        {
            ans = f(i - 1, s, cnt, dp);
            int cur = own[i];
            int times = cnt[i];
            if (cur != 0 && times != 0 && (s & cur) == cur)
                ans = (int)(((long long)f(i - 1, s ^ cur, cnt, dp) * times + ans) % mod);
        }
        dp[i][s] = ans;
        return ans;
    }
    int numberOfGoodSubsets(vector<int> &nums)
    {
        vector<int> cnt(maxv + 1);
        for (int num : nums) // 统计频率
            cnt[num]++;
        vector<vector<int>> dp(maxv + 1, vector<int>(limit, -1));
        int ans = 0;
        for (int s = 1; s < limit; s++)
            ans = (ans + f(maxv, s, cnt, dp)) % mod;
        return ans;
    }
};