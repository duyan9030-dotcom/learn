#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int deque[100001];
    int h, t;
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        h = t = 0;
        int n = nums.size();
        vector<int> a(n-k+1);
        for (int i = 0; i < k - 1; i++)
        {
            while(h<t&&nums[deque[t-1]]<=nums[i])
                t--;
            deque[t++] = i;
        }
        for (int l = 0, r = k - 1; l < n - k + 1;l++,r++)
        {
            while (h < t && nums[deque[t - 1]] <= nums[r])
                t--;
            deque[t++] = r;
            a[l]=nums[deque[h]];
            if(deque[h]==l)
                h++;
        }
        return a;
    }
};