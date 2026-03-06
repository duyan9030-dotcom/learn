// https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxdeque[100001];
    int mindeque[100001];
    int maxh, maxt, minh, mint;
    vector<int> arr;
    bool ok(int limit,int number)
    {
        int ma = maxh < maxt ? max(arr[maxdeque[maxh]], number) : number;
        int mi = minh < mint ? min(arr[mindeque[minh]], number) : number;
        return ma - mi <= limit;
    }
    void push(int r)
    {
        while(maxh<maxt&&arr[maxdeque[maxt-1]]<=arr[r])
            maxt--;
        maxdeque[maxt++] = r;
        while(minh<mint&&arr[mindeque[mint-1]]>=arr[r])
            mint--;
        mindeque[mint++] = r;
    }
    void pop(int l)
    {
        if(maxh<maxt&&maxdeque[maxh]==l)
            maxh++;
        if(minh<mint&&mindeque[minh]==l)
            minh++;
    }
    int longestSubarray(vector<int> &nums, int limit)
    {
        maxh = maxt = minh = mint = 0;
        arr = nums;
        int n = arr.size();
        int ans = 0;
        for (int l = 0, r = 0; l < n;l++)
        {
            while(r<n&&ok(limit,nums[r]))
                push(r++);
            ans = max(ans, r - l);
            pop(l);
        }
        return ans;
    }
};