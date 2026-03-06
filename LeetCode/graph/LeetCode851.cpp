#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int head[505];
    int nexts[250005];
    int to[250005];
    int cnt = 1;
    int indegree[505];
    void addedge(int u, int v)
    {
        nexts[cnt] = head[u];
        to[cnt] = v;
        head[u] = cnt++;
        indegree[v]++;
    }
    vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
    {
        for (auto b : richer) // 建图
            addedge(b[0], b[1]);
        int queue[505];
        int l = 0, r = 0;
        vector<int> ans((int)quiet.size());
        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = i;
            if(indegree[i]==0)
                queue[r++] = i;
        }
        while(l<r)
        {
            int cur = queue[l++];
            for (int i = head[cur], v; i > 0;i=nexts[i])
            {
                v = to[i];
                if(quiet[ans[v]]>quiet[ans[cur]])
                {
                    ans[v] = ans[cur];
                }
                if(--indegree[v]==0)
                    queue[r++] = v;
            }
        }
        return ans;
    }
};