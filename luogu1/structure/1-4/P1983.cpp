#include <bits/stdc++.h>
using namespace std;
int head[1005];
int nexts[1000005];
int to[1000005];
int cnt = 1;
int indegree[1005];
int exist[1005][1005];
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
    indegree[v]++;
    exist[u][v] = 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int stations[1005];
    for (int i = 0; i < m; i++)
    {
        memset(stations, 0, sizeof(stations));
        int s, start, end;
        cin >> s;
        vector<int> a(s);
        for (int j = 0; j < s; j++)
        {
            cin >> a[j];
            stations[a[j]] = 1;
        }
        start = a[0], end = a[s - 1];
        for (int k = start; k <= end; k++)
        {
            if (stations[k] == 0)
                for (int j = 0; j < s; j++)
                    if (exist[k][a[j]] == 0)
                        addedge(k, a[j]);
        }
    }
    int level = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int cur = q.front();
            q.pop();
            for (int ei = head[cur]; ei > 0; ei = nexts[ei])
                if (--indegree[to[ei]] == 0)
                    q.push(to[ei]);
        }
        level++;
    }

    cout << level;
}