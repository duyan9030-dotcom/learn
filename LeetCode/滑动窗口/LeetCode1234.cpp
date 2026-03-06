// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int balancedString(string s)
    {
        const int n = s.size();
        int cnts[4];
        int str[n];
        for (int i = 0; i < n;i++)
        {
            str[i] = s[i] == 'W' ? 1 : (s[i] == 'E' ? 2 : (s[i] == 'R' ? 3 : 0));
            cnts[str[i]]++;
        }
        int debt = 0;
        for (int i = 0; i < 4;i++)
        {
            if (cnts[i] < (n / 4))
                cnts[i] = 0;
            else{
                cnts[i] = n / 4 - cnts[i];
                debt -= cnts[i];
            }
        }
        if(debt==0)
            return 0;
        int ans = INT_MAX;
        for (int l = 0, r = 0; r < n;r++)
        {
            if(cnts[str[r]]++<0)
                debt--;
            if(debt==0)
            {
                while(cnts[str[l]]>0)
                    cnts[str[l++]]--;
                ans = min(ans, r - l + 1);
            }
        }
        return ans;
    }
};