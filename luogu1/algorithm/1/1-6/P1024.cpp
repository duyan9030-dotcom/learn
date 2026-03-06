#include <bits/stdc++.h>
using namespace std;
double a, b, c, d,mid;
int s = 0;
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}
int main()
{

    cin >> a >> b >> c >> d;
    for (int i = -100; i < 100; i++)
    {
        double l = i, r = i + 1;
        if (!f(l))
        {
            printf("%.2lf ", l);
            s++;
        }
        if (f(l) * f(r) < 0)
        {
            while (r - l >= 0.001)
            {
                mid = (l + r) / 2;
                if (f(mid) * f(r) > 0)
                    r = mid;
                else
                    l = mid;
            }
            printf("%.2lf ", mid);
            s++;
        }
        if (s == 3)
            break;
    }
}