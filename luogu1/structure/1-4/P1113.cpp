//拓扑排序+dp
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int indegree;
    vector<int> v;
    int len;
};
int q[10005];
int l = 0, r = 0;
int dp[10005];
int main()
{
    int n;
    cin >> n;
    vector<node> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int num, len, v;
        cin >> num >> len;
        g[num].len = len;
        while (1)
        {
            cin >> v;
            if (v == 0)
                break;
            g[v].v.push_back(num);
            g[num].indegree++;
        }
    }
    for (int i = 1; i <= n; i++)
        if (g[i].indegree == 0)
        {
            q[r++] = i;
            dp[i] = g[i].len;
        }
    int ans = 0;
    int lsize;
    while (l < r)
    {
        int cur = q[l++];
        ans = max(ans, dp[cur]);
        for (int a : g[cur].v)
        {
            dp[a] = max(dp[a],dp[cur]+g[a].len);
            if (--g[a].indegree == 0)
                q[r++] = a;
        }
    }
    cout << ans;
    return 0;
}