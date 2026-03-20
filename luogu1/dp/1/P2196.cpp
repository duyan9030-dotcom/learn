#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int g[25][25];
int a[25]; // 从某个点开始挖能挖出来的最大地雷数
int n;
vector<int> anspath;
int maxans = -1;
void dfs(int i, int ans, vector<int> &path)
{
    if (maxans < ans)
    {
        maxans = ans;
        anspath = path;
    }
    for (int j = i + 1; j <= n; j++)
    {
        if (g[i][j])
        {
            path.push_back(j);
            dfs(j, ans + a[j], path);
            path.pop_back();
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            cin >> g[i][j];
            g[j][i] = g[i][j];
        }
    }
    queue<pair<int, vector<int>>> q;
    for (int i = 1; i <= n; i++)
    {
        vector<int> path;
        path.push_back(i);
        dfs(i, a[i], path);
    }
    for (int x : anspath)
        cout << x << " ";
    cout << endl
         << maxans;
}