#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int where[100005];
int b[100005];
int n;
int endds[100005];
int bs(int len, int num)
{
    int l = 0, r = len - 1, m, ans = -1;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (endds[m] >= num)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return ans;
}
int lis()
{
    int len = 0;
    for (int i = 0, find; i < n; i++)
    {
        find = bs(len, b[i]);
        if (find == -1)
            endds[len++] = b[i];
        else
            endds[find] = b[i];
    }
    return len;
}
int main()
{
    cin >> n;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        where[a] = i;
    }
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        b[i] = where[a];
    }
    cout << lis();
    return 0;
}