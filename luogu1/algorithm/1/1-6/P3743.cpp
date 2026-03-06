#include <bits/stdc++.h>
using namespace std;
double check(vector<pair<double, double>> a,double mid)
{
    double sum = 0;
    for (auto x : a)
    {
        if (x.second >= mid * x.first)
            continue;
        else
            sum += mid * x.first - x.second;
    }
    return sum;
}
int main()
{
    int n;
    double p, suma;
    cin >> n >> p;
    vector<pair<double, double>> ab(n);
    for (auto &a : ab)
    {
        cin >> a.first >> a.second;
        suma += a.first;
    }
    if (p >= suma)
    {
        cout << (-1);
        return 0;
    }
    double l = 0, r = 3e10, mid;
    while (r - l > 1e-6)
    {
        mid = (l + r) / 2;
        if (check(ab, mid) <= p * mid)
            l = mid;
        else
            r = mid;
    }
    cout << l;
}
