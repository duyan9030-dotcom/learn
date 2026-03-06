#include <bits/stdc++.h>
using namespace std;
class au
{
public:
    int m, v;
    double avg = 0;
};
bool cmp(au i1, au i2)
{
    return i1.avg > i2.avg;
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<au> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].m >> a[i].v;
        a[i].avg = (double)a[i].v / a[i].m;
    }
    sort(a.begin(), a.end(), cmp);
    double price = 0;
    for (int i = 0; i < n && t > 0; i++)
    {
        price += (t - a[i].m >= 0) ? a[i].v : t * a[i].avg;

        t -= a[i].m;
    }
    printf("%.2lf", price);
}