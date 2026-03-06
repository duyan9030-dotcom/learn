#include <bits/stdc++.h>
using namespace std;
struct zb
{
    double x, y, z;
};
bool cmp(zb a, zb b)//最低点到最高点只需要看z
{
    return a.z < b.z;
}
int main()
{
    int n;
    cin >> n;
    double s = 0;
    vector<zb> lc(n);
    for (int i = 0; i < n; i++)
        cin >> lc[i].x >> lc[i].y >> lc[i].z;
    sort(lc.begin(), lc.end(), cmp);
    for (int i = 1; i < n; i++)
        s += sqrt((lc[i].x - lc[i - 1].x) * (lc[i].x - lc[i - 1].x) + (lc[i].y - lc[i - 1].y) * (lc[i].y - lc[i - 1].y) + (lc[i].z - lc[i - 1].z) * (lc[i].z - lc[i - 1].z));
    printf("%.3lf", s);
    return 0;
}