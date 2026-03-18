#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int nexts[1000005],n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> s;
    nexts[0] = -1;
    nexts[1] = 0;
    int i = 2, cn = 0;
    while (i <= n)
    {
        if(s[i-1]==s[cn])
            nexts[i++] = ++cn;
        else if(cn>0)
            cn = nexts[cn];
        else
            nexts[i++] = 0;
    }
    cout << n - nexts[n];
}