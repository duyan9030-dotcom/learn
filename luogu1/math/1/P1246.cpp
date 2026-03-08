#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int C[30][30];
void build()
{
    for (int i = 0; i <= 26; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    string s;
    cin >> s;
    for (int i = 1; i < s.size(); i++)//检验合法性
    {
        if (s[i] <= s[i - 1])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 0;
    for (int i = 1; i < s.size(); i++)//所有长度比他小的
        ans += C[26][i];
    int start = 1;
    for (int i = 0; i < s.size(); i++)//长度一样但字典序更小的
    {
        int cur = s[i] - 'a' + 1;
        for (int j = start; j < cur; j++)
        {
            ans += C[26 - j][s.size() - 1 - i];
        }
        start = cur + 1;
    }
    cout << ans + 1 << endl;
    return 0;
}