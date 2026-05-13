#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int p[2005];
    int countSubstrings(string s)
    {
        string cs = "#";
        for (char c : s)
        {
            cs += c;
            cs += '#';
        }
        int n = cs.size();
        for (int i = 0, r = 0, c = 0, len; i < n; i++)
        {
            len = r > i ? min(p[2 * c - i], r - i) : 1;
            while (i + len < n && i - len >= 0 && cs[i + len] == cs[i - len])
                len++;
            if (i + len > r)
                r = i + len, c = i;
            p[i] = len;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += p[i] / 2;
        return ans;
    }
};