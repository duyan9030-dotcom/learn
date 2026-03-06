#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int head[5 * 10000+5];
    int nexts[250005];
    int to[250005];
    int cnt = 1;
    int indegree[5 * 10000+5];
    void addedge(int u, int v)
    {
        nexts[cnt] = head[u];
        to[cnt] = v;
        head[u] = cnt++;
        indegree[v]++;
    }
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        for (auto b : relations) // 建图
            addedge(b[0], b[1]);
        int queue[5*10000+5];
        int l = 0, r = 0;
        vector<int> ans(n + 1);
        for (int i = 1; i < ans.size(); i++)
            if (indegree[i] == 0)
                queue[r++] = i;
        int m = 0;
        while (l < r)
        {
            int cur = queue[l++];
            ans[cur] += time[cur - 1];
            m = max(m, ans[cur]);
            for (int i = head[cur], v; i > 0; i = nexts[i])
            {
                v = to[i];
                ans[v] = max(ans[cur], ans[v]);
                if (--indegree[v] == 0)
                    queue[r++] = v;
            }
        }
        return m;
    }
};