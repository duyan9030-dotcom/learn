#include <bits/stdc++.h>
using namespace std;
int main()
{
    int w0, w, m;
    cin >> w0 >> w >> m;
    double l = 0, r = 1000,mid;
    while(r-l>=0.0001)
    {
        mid = (l + r) / 2;
        double sum = w0;
        for (int i = 0; i < m;i++)
            sum = sum - w + sum * (mid / 100);
        
        if(sum>0.0001)
            r = mid;
        else
            l = mid;
    }
    printf("%.1lf", l);
}