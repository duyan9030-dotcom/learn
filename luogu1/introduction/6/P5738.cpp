#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    double s=0, t=0;
    for (int i = 0; i < n; i++)
    {
        double count = 0, mi=0, ma=0, x;
        cin >> x;
        mi = ma =count= x;
        for (int j = 1; j < m; j++)
        {
            cin >> x;
            count += x;
            mi = j==0?x:min(mi,x);
            ma = max(ma, x);
            t = (count - mi - ma) / (m - 2);
        }
        s = max(s, t);
    }
    printf("%.2lf", s);
    return 0;
}