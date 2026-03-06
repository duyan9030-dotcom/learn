// 双向广搜
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lsum[1 << 20];
    int rsum[1 << 20];
    int fill;
    void collect(vector<int>& nums, int i, int e, int s, int sum[])
    {
        if(i==e)
            sum[fill++] = s;
        else{
            int j = i + 1;
            while(j<e&&nums[j]==nums[i])
                j++;
            for (int k = 0; k <= j - i;k++)
                collect(nums, j, e, s + k * nums[i], sum);
        }
    }
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        long long mn = 0;
        long long mx = 0;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                mx += nums[i];
            else
                mn += nums[i];
        if (mx < goal)
            return (int)abs(goal - mx);
        if (mn > goal)
            return (int)abs(goal - mn);
        sort(nums.begin(), nums.end());
        fill = 0;
        collect(nums, 0, n >> 1, 0, lsum);
        int lsize = fill;
        fill = 0;
        collect(nums, n >> 1, n, 0, rsum);
        int rsize = fill;
        sort(lsum, lsum + lsize);
        sort(rsum, rsum + rsize);
        int ans = abs(goal);
        for (int i = 0, j = rsize - 1; i < lsize;i++)
        {
            while(j>0&&abs(goal-lsum[i]-rsum[j-1])<=abs(goal-lsum[i]-rsum[j]))
                j--;
            ans = min(ans, abs(goal - lsum[i] - rsum[j]));
        }
        return ans;
    }
};