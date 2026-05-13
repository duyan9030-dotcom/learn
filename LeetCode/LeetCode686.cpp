#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef unsigned long long ll;
    const ll base = 499;
    ll power[30005];
    ll hash[30005];
    string s = "";
    void build()
    {
        power[0] = 1;
        for (int i = 1; i <= 30000; i++)
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
    int repeatedStringMatch(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        int k = (m + n - 1) / n;
        s = "";
        for (int i = 0; i <= k; i++)
            s += a;
        build();
        ll hashvalue = b[0] - 'a' + 1;
        for (int i = 1; i < b.size(); i++)
            hashvalue = hashvalue * base + b[i] - 'a' + 1;
        int l = 0, r = m - 1;
        while (r < s.size())
        {
            if (hashv(l, r) == hashvalue)
            {
                return r < n * k ? k : k + 1;
            }
            l++, r++;
        }
        return -1;
    }
};