#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>> map(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];
    for (int i = 1; i <= m; i++)
        map[0][i] += map[0][i - 1];
    for (int i = 1; i <= n; i++)
        map[i][0] += map[i - 1][0];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            map[i][j] += map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1];
    // 枚举左上角坐标
    int ai, aj, ans = -1e9;
    for (int i = 1; i <= n - c + 1; i++)
    {
        for (int j = 1; j <= m - c + 1; j++)
        {
            int cur = map[i + c - 1][j + c - 1] - map[i + c - 1][j - 1] - map[i - 1][j + c - 1] + map[i - 1][j - 1];
            if (cur > ans)
            {
                ai = i;
                aj = j;
                ans = cur;
            }
        }
    }
    cout << ai << " " << aj;
}