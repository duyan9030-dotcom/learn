#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,ma,mi;
    double count = 0.0;
    cin >> n;
    cin >> x;
    ma = x, mi = x,count+=x;
    for (int i = 1; i < n;i++)
    {
        cin >> x;
        count += x;
        ma = max(ma, x);
        mi = min(mi, x);
    }
    printf("%.2lf", (count - ma - mi) / (n-2));
    return 0;
}
