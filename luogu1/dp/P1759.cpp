// #include <bits/stdc++.h>
// using namespace std;
// const int mod = 1e9 + 7;
// int main()
// {
//     int n, m, v;
//     cin >> m >> v >> n;
//     vector<int> a(n + 1), b(n + 1), c(n + 1);
//     for (int i = 1; i <= n; i++)
//         cin >> a[i] >> b[i] >> c[i];
//     vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(v + 1, 0)));
//     vector<vector<vector<string>>> path(n + 1, vector<vector<string>>(m + 1, vector<string>(v + 1, "")));
//     string p2;
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 0; j <= m; j++)
//         {
//             for (int k = 0; k <= v; k++)
//             {
//                 dp[i][j][k] = dp[i - 1][j][k];
//                 path[i][j][k] = path[i - 1][j][k];
//                 if (j >= a[i] && k >= b[i])
//                 {
//                     if (path[i - 1][j - a[i]][k - b[i]] == "")
//                     {
//                         p2 = to_string(i);
//                     }
//                     else
//                     {
//                         p2 = path[i - 1][j - a[i]][k - b[i]] + " " + to_string(i);
//                     }
//                     if (dp[i][j][k] < dp[i - 1][j - a[i]][k - b[i]] + c[i])
//                     {
//                         dp[i][j][k] = dp[i - 1][j - a[i]][k - b[i]] + c[i];
//                         path[i][j][k] = p2;
//                     }
//                     else if (dp[i][j][k] == dp[i - 1][j - a[i]][k - b[i]] + c[i])
//                     {
//                         if (p2 < path[i][j][k])
//                             path[i][j][k] = p2;
//                     }
//                 }
//             }
//         }
//     }
//     cout << dp[n][m][v] << endl;
//     cout << path[n][m][v] << endl;
// }
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int n, m, v;
    cin >> m >> v >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    vector<vector<int>> dp(m + 1, vector<int>(v + 1, 0));
    vector<vector<string>> path(m + 1, vector<string>(v + 1, ""));
    string p2;
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= a[i]; j--)
        {
            for (int k = v; k >= b[i]; k--)
            {
                p2 = (path[j - a[i]][k - b[i]] == "") ? to_string(i) : path[j - a[i]][k - b[i]] + " " + to_string(i);
                if (dp[j][k] < dp[j - a[i]][k - b[i]] + c[i])
                {
                    dp[j][k] = dp[j - a[i]][k - b[i]] + c[i];
                    path[j][k] = p2;
                }
                else if (dp[j][k] == dp[j - a[i]][k - b[i]] + c[i])
                {
                    if (p2 < path[j][k])
                        path[j][k] = p2;
                }
            }
        }
    }
    cout << dp[m][v] << endl;
    cout << path[m][v] << endl;
}
