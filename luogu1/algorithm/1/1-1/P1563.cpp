#include <bits/stdc++.h>
using namespace std;
//0圈内1圈外
//0左1右
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    vector<string> name(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> name[i];
    int l = 0;
    for (int i = 0; i < m; i++)
    {
        int lr,val;
        cin >> lr>> val;//n进制，逆时针01/10 减，顺时针11/00 加，最后都取模
        if (x[l] == lr)
            l = (l - val+n) % n;
        else
            l = (l + val) % n;
    }
    cout << name[l];
    return 0;
}