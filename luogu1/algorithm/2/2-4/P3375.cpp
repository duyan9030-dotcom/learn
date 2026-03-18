// kmp
#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
vector<int> buildnext(string s, int m)
{
    vector<int> next(m + 1);
    if (m == 1)
        return next;
    int i = 2, cn = 0;
    while (i <= m)
        if (s[i - 1] == s[cn])
            next[i++] = ++cn;
        else if (cn > 0)
            cn = next[cn];
        else
            next[i++] = 0;
    return next;
}
void kmp(string s1, string s2)
{
    int n = s1.size(), m = s2.size(), x = 0, y = 0;
    vector<int> next = buildnext(s2, m);
    while (x < n)
    {
        if (s1[x] == s2[y])
            x++, y++;
        else if (y == 0)
            x++;
        else
            y = next[y];
        if (y == m)
        {
            cout << (x - y) + 1 << endl;
            y = next[y];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    kmp(s1, s2);
    vector<int> next = buildnext(s2, s2.size());
    for (int i = 1; i <= s2.size(); i++)
        cout << next[i] << " ";
}

