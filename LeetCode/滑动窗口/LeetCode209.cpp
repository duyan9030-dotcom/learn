// https://leetcode.cn/problems/minimum-size-subarray-sum
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int start = 0, end = 0, m = INT_MAX, sum = 0;
        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target)
            {
                m = min(m, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return m == INT_MAX ? 0 : m;
    }
};