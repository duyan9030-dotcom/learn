#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef unsigned long long ll;
    const ll base = 499;
    ll power[30005];
    ll hash[30005];
    void build(string s)
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
    ll hashturn(string t)
    {
        if (t == "")
            return 0;
        int n = t.length();
        ll ans = t[0] - 'a' + 1;
        for (int i = 1; i < n; i++)
            ans = ans * base + t[i] - 'a' + 1;
        return ans;
    }
    vector<int> findSubstring(string s, vector<string> &words)
    {
        vector<int> ans;
        if (s.length() == 0 || words.size() == 0)
            return ans;
        map<ll, int> m;
        for (string s : words)
        {
            ll v = hashturn(s);
            m[v]++;
        }
        build(s);
        int n = s.size();
        int wordlen = words[0].length();
        int wordnum = words.size();
        int alllen = wordlen * wordnum;
        map<ll, int> win;
        for (int init = 0; init < wordlen && init + alllen <= n; init++)
        {
            int debt = wordnum;
            for (int l = init, r = init + wordlen - 1, part = 0; part < wordnum; l += wordlen, r += wordlen, part++)
            {
                ll cur = hashv(l, r);
                win[cur]++;
                if (win[cur] <= m[cur])
                    debt--;
            }
            if (debt == 0)
                ans.push_back(init);
            for (int l1 = init, r1 = init + wordlen - 1, l2 = init + alllen, r2 = init + alllen + wordlen - 1; r2 < n; l1 += wordlen, l2 += wordlen, r1 += wordlen, r2 += wordlen)
            {
                ll out = hashv(l1, r1);
                ll in = hashv(l2, r2);
                win[out]--;
                if (win[out] < m[out])
                    debt++;
                win[in]++;
                if (win[in] <= m[in])
                    debt--;
                if (debt == 0)
                    ans.push_back(l1 + wordlen);
            }
            win.clear();
        }
        return ans;
    }
};