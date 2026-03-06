// https://leetcode.cn/problems/gas-station
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        const int n = gas.size();
        int sub[2 * n];
        for (int i = 0; i < 2*n;i++)
            sub[i] = gas[i%n] - cost[i%n];
        for (int l = 0, r = 0, sum = 0; r < 2 * n;r++)
        {
            sum += sub[r];
            if(sum<0)
            {
                l = r + 1;
                sum = 0;
            }
            if(r-l+1==n)
                return l;
        }
        return -1;
    }
};