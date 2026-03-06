#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumInvitations(vector<int> &favorite)
    {
        int n = favorite.size();
        vector<int> indegree(n, 0);
        for (int x : favorite)
            indegree[x]++; // 入度
        int queue[n];
        int l = 0, r = 0;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                queue[r++] = i;
        vector<int> deep(n, 0);
        while (l < r) // 除了环上的点全删掉
        {
            int cur = queue[l++];
            int next = favorite[cur];
            deep[next] = max(deep[next], deep[cur] + 1); // deep[i]外层的第一个点从0开始向内转移
            if (--indegree[next] == 0)
                queue[r++] = next;
        }
        int sr = 0, br = 0; // 环的点==2的人数sr，环的点>2的人数br
        for (int i = 0; i < n; i++)
            if (indegree[i] > 0) // 从环上的某个点进入
            {
                int ms = 1;
                indegree[i] = 0;
                for (int j = favorite[i]; j != i; j = favorite[j])
                {
                    ms++;
                    indegree[j] = 0; // 走过的点入度标为0不再走
                }
                if (ms == 2) // 小环的最大人数就是最长链点的个数
                    sr += deep[i] + deep[favorite[i]] + 2;
                else // 大环的最大人数就是最大环点的个数
                    br = max(br, ms);
            }
        return max(sr, br);
    }
};