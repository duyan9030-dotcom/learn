#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int factors[100001];
    int father[20001];
    int size[20001];
    int n;
    void build()
    {
        for (int i = 0; i < n; i++)
        {
            father[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < 100001; i++)
            factors[i] = -1;
    }
    int find(int a)
    {
        if (a != father[a])
            father[a] = find(father[a]);
        return father[a];
    }
    void unio(int a, int b)
    {
        int fa = find(a);
        int fb = find(b);
        if (fa != fb)
        {
            father[fa] = fb;
            size[fb] += size[fa];
        }
    }
    int maxsize()
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, size[i]);
        return ans;
    }

    int largestComponentSize(vector<int> &nums)
    {
        n = nums.size();
        build();
        for (int i = 0, x; i < n; i++)
        {
            x = nums[i];
            for (int j = 2; j * j <= x; j++)
            {
                if (x % j == 0)
                {
                    if (factors[j] == -1)
                        factors[j] = i;
                    else
                        unio(factors[j], i);//根据质因数分组
                    while (x % j == 0)//除干净
                        x /= j;
                }
            }
            if(x>1)
            {
                if (factors[x] == -1)
                    factors[x] = i;
                else
                    unio(factors[x], i);
            }
        }
        return maxsize();
    }
};