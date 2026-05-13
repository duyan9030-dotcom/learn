#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef unsigned long long ll;
    const int base = 499;
    ll power[10005];
    ll hash[10005];
    string s, t;
    void build()
    {
        power[0] = 1;
        for (int i = 1; i <= 10000; i++)
            power[i] = power[i - 1] * base;
        hash[0] = s[0] - 'a' + 1;
        for (int i = 1; i < s.size(); i++)
            hash[i] = hash[i - 1] * base + s[i] - 'a' + 1;
    }
    ll hashv(int l, int r)
    {
        ll ans = hash[r];
        if (l > 0)
            ans -= hash[l - 1] * power[r - l + 1];
        return ans;
    }
    int strStr(string haystack, string needle)
    {
        s = haystack;
        t = needle;
        build();
        ll hashvalue = t[0] - 'a' + 1;
        for (int i = 1; i < t.size(); i++)
            hashvalue = hashvalue * base + t[i] - 'a' + 1;
        int l = 0, r = t.size() - 1;
        while (r < s.size())
        {
            if (hashvalue == hashv(l, r))
                return l;
            l++, r++;
        }
        return -1;
    }
};