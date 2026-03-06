#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n, m;
    vector<int> getMaxMatrix(vector<vector<int>> &matrix)
    {
        vector<int> xy(4);
        int sum = INT_MIN;
        n = matrix.size();
        m = matrix[0].size();
        vector<int> a(m);
        for (int i = 0; i < n; i++)
        {
            fill(a.begin(), a.end(), 0);
            for (int j = i; j < n; j++)
            {
                for (int l = 0, r = 0, pre = INT_MIN; r < m;r++)
                {
                    a[r] += matrix[j][r];
                    if(pre>=0)
                        pre += a[r];
                    else
                    {
                        pre = a[r];
                        l = r;
                    }
                    if(pre>sum)
                    {
                        sum = pre;
                        xy[0] = i;
                        xy[2] = j;
                        xy[1] = l;
                        xy[3] = r;
                    }
                    
                }
            }
        }
        return xy;
    }
};