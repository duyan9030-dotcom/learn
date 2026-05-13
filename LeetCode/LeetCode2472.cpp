#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    int p[4005];
    string ss;
    int find(int l, int k)
    {
        for (int i = l, r = l, c = l, len; i < n; i++)
        {
            len = r > i ? min(p[2 * c - i], r - i) : 1;
            while (i + len < n && i - len >= l && ss[i + len] == ss[i - len])
                if (++len > k)
                    return i + k + (ss[i + k] == '#' ? 0 : 1);
            if (i + len > r)
            {
                r = i + len;
                c = i;
            }
            p[i] = len;
        }
        return -1;
    }
    int maxPalindromes(string s, int k)
    {
        int ans = 0;
        int next = 0;
        ss = "#";
        for (char c : s)
        {
            ss += c;
            ss += '#';
        }
        n = ss.size();
        while ((next = find(next, k)) != -1)
            ans++;
        return ans;
    }
};