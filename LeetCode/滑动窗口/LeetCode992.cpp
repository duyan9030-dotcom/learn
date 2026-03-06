// https://leetcode.cn/problems/subarrays-with-k-different-integers/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return f(nums, k) - f(nums, k - 1);
    }
    int cnts[20001];
    int f(vector<int> &nums, int k)
    {
        memset(cnts, 0, sizeof(cnts));
        int ans = 0;
        for (int l = 0, r = 0, collect = 0; r < nums.size(); r++)
        {
            if (++cnts[nums[r]] == 1)
            {
                collect++;
            }
            while (collect > k)
            {
                if (--cnts[nums[l++]] == 0)
                {
                    collect--;
                }
            }
            ans += r - l + 1;
        }
        return ans;
    }
};