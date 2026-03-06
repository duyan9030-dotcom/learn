#include <bits/stdc++.h>
using namespace std;
struct p
{
    int i;
    string name;
    int y, m, d;
};
bool cmp(p a, p b)
{
    if (a.y != b.y)
        return a.y < b.y;
    else if (a.m != b.m)
        return a.m < b.m;
    else if (a.d != b.d)
        return a.d < b.d;
    else
        return a.i > b.i;
}
int main()
{
    int n;
    cin >> n;
    vector<p> c(n);
    for (int i = 0; i < n; i++)
    {
        cin >> c[i].name >> c[i].y >> c[i].m >> c[i].d;
        c[i].i = i;
    }
    sort(c.begin(), c.end(), cmp);
    for (int i = 0; i < n; i++)
        cout << c[i].name<<endl;
    return 0;
}