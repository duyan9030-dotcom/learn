// https://leetcode.cn/problems/minimum-window-substring
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int l = 0, r = 0, ans = INT_MAX, start = 0;
        int q[256];
        int debt = 0; // 欠债
        for (int i = 0; i < t.size(); i++)
            q[t[i]]--;
        debt = t.size();
        for (int l = 0, r = 0; r < s.size(); r++)
        {
            if (q[s[r]]++ < 0)
                debt--;
            if (debt == 0)
            {
                while (q[s[l]] > 0)
                    q[s[l++]]--;
                if(r-l+1<ans)
                {
                    ans = r - l + 1;
                    start = l;
                }
            }
        }
        return ans == INT_MAX ? "" : s.substr(start, ans);
    }
};