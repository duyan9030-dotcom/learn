#include <bits/stdc++.h>
using namespace std;
double pf(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1-x2),2)+pow((y1-y2),2));
}
int main()
{
    double x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    printf("%.2lf", pf(x1, y1, x2, y2) + pf(x1, y1, x3, y3) + pf(x2, y2, x3, y3));
    return 0;
}
