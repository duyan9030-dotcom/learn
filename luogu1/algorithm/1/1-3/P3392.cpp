#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m,ans,mi=INT_MAX;
    cin >> n >> m;
    vector<string> s(n+1);
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            ans = 0;
            for (int k = 1; k <=i; k++)
                for (int l = 0; l < m; l++)
                    if (s[k][l] != 'W')
                        ans++;
            for (int k = i+1; k <= j; k++)
                for (int l = 0; l < m; l++)
                    if (s[k][l] != 'B')
                    
                        ans++;
            for (int k = j+1; k <=n; k++)
                for (int l = 0; l < m; l++)
                    if (s[k][l] != 'R')
                        ans++;
            mi = min(mi, ans);
        }
    }
    cout << mi;
    return 0;
}
