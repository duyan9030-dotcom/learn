#include <bits/stdc++.h>
using namespace std;
int head[30], nexts[605], to[605], cnt = 1, indegree[30];
int n, m;
vector<char> s;
bool a[30];
void addedge(int u, int v)
{
    nexts[cnt] = head[u];
    to[cnt] = v;
    head[u] = cnt++;
    indegree[v]++;
    a[u] = a[v] = true;
}
int tps()
{
    s.clear();
    queue<int> q;
    bool determent = true;
    int cindegree[30];
    for (int i = 1; i <= n; i++)
        cindegree[i] = indegree[i];
    int sum = 0; // 当前点的总数
    for (int i = 1; i <= n; i++)
    {
        if (cindegree[i] == 0 && a[i])
            q.push(i);
        if(a[i])
            sum++;
    }
    while (!q.empty())
    {
        if (q.size() > 1)
            determent = false;
        int cur = q.front();
        q.pop();
        s.push_back('A' + cur - 1);
        for (int ei = head[cur]; ei > 0; ei = nexts[ei])
            if (--cindegree[to[ei]] == 0)
                q.push(to[ei]);
    }
    if (s.size() < sum)
        return 2;
    if (determent && s.size() == n)
        return 1;
    return 0;
}
int main()
{
    char a, b, c;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        addedge(a - 'A' + 1, c - 'A' + 1);
        int result = tps();
        if (result == 2) // 有环矛盾
        {
            cout << "Inconsistency found after " << i << " relations.";
            return 0;
        }
        if (result == 1)
        {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (char k : s)
                cout << k;
            cout << '.';
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined.";
    return 0;
}