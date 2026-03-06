#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    double a = 0, b = 0;
    double j = 0, z = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % k == 0)
        {
            a += i;
            j++;
        }
        else
        {
            b += i;
            z++;
        }
    }
    printf("%.1lf %.1lf", a / j, b / z);
    return 0;
}

