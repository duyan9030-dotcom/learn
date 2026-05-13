#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int p[2005];
    string longestPalindrome(string s)
    {
        string cs = "#";
        for (char c : s)
        {
            cs += c;
            cs += '#';
        }
        int n = cs.size();
        string ans = "";
        int ae = 0, alen = 0;
        for (int i = 0, r = 0, c = 0, len; i < n; i++)
        {
            len = r > i ? min(p[2 * c - i], r - i) : 1;
            while (i + len < n && i - len >= 0 && cs[i + len] == cs[i - len])
                len++;
            if (i + len > r)
                r = i + len, c = i;
            if (len - 1 > alen)
            {
                alen = len - 1;
                ae = (i + len - 2) / 2;
            }
            p[i] = len;
        }
        // for (int i = ae - alen + 1; i <= ae; i++)
        //     ans += s[i];
        return s.substr(ae - alen, alen);
    }
};