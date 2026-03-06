#include <bits/stdc++.h>
using namespace std;
struct a
{
    int num, day;
};
bool cmp(a x,a y)
{
    return x.num < y.num;
}
int main()
{
    int n;
    long long sum = 0;
    cin >> n;
    vector<a> p(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].num;
        p[i].day = i;
    }
    sum += p[0].num;
    sort(p.begin()+1, p.end(), cmp);
    for (int i = 1; i < n;i++)
    {
        
    }
        // for (int i = 1; i < n; i++)
        // {
        //     int m = 0;
        //     for (int j = 1; j < i; j++)
        //         m = abs(p[j] - p[i]) < abs(p[m] - p[i]) ? j : m;
        //     sum += abs(p[m] - p[i]);
        // }
        cout << sum;
}