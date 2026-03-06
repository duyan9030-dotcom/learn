#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    struct node
    {
        vector<int> v;
        vector<int> w;
    };
    node g[101];
    void addedge(int &u, int &v, int &w)
    {
        g[u].v.push_back(v);
        g[u].w.push_back(w);
    }
    struct cmp
    {
        bool operator()(const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.second > b.second;
        }
    };
    int distance[101];
    bool visited[101];
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        for (auto s : times)
            addedge(s[0], s[1], s[2]);
        fill(distance, distance + 101, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        distance[k] = 0;
        q.push({k, 0});
        while (!q.empty())
        {
            int u = q.top().first;
            q.pop();
            if (!visited[u])
            {
                visited[u] = true;
                for (int i = 0; i < g[u].v.size(); i++)
                {
                    int v = g[u].v[i];
                    int w = g[u].w[i];
                    if (!visited[v] && distance[u] + w < distance[v])
                    {
                        distance[v] = distance[u] + w;
                        q.push({v, distance[u] + w});
                    }
                }
            }
        }
        int m = -1;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == 1e9)
                return -1;
            m = max(m, distance[i]);
        }
        return m;
    }
};