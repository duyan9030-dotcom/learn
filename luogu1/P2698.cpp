#include <bits/stdc++.h>
using namespace std;
struct water
{
    int x, y;
};
int n, d;
water rain[100001];
int maxdeque[100001];
int mindeque[100001];
int maxh, maxt, minh, mint;
bool ok()
{
    int ma = maxh < maxt ? rain[maxdeque[maxh]].y : 0;
    int mi = minh < mint ? rain[mindeque[minh]].y : 0;
    return ma - mi >= d;
}
void push(int r)
{
    while (maxh < maxt && rain[maxdeque[maxt - 1]].y <= rain[r].y)
        maxt--;
    maxdeque[maxt++] = r;
    while (minh < mint && rain[mindeque[mint - 1]].y >= rain[r].y)
        mint--;
    mindeque[mint++] = r;
}
void pop(int l)
{
    if (maxh < maxt && maxdeque[maxh] == l)
        maxh++;
    if (minh < mint && mindeque[minh] == l)
        minh++;
}
int main()
{
    cin >> n >> d;
    for (int i = 0; i < n; i++)
        cin >> rain[i].x >> rain[i].y;
    sort(rain, rain + n, [](water a, water b)
         { return a.x < b.x; });
    int ans = INT_MAX;
    maxh = maxt = minh = mint = 0;
    for (int l = 0, r = 0; l < n; l++)
    {
        while (!ok() && r < n)
            push(r++);
        if (ok())
            ans = min(ans, rain[r - 1].x - rain[l].x);
        pop(l);
    }
    cout << (ans == INT_MAX ? -1 : ans);
}
