#include <bits/stdc++.h>
using namespace std;
struct p
{
    int id;
    int s;
};
bool cmp(p a, p b)
{
    if (a.s != b.s)
        return a.s > b.s;
    return a.id < b.id;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int sum =m*1.5;
    vector<p> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i].id >> xs[i].s;
    sort(xs.begin(), xs.end(), cmp);
    for (int i = sum; i < n; i++)
        sum += xs[i].s == xs[sum - 1].s ? 1 : 0;
    cout << xs[sum-1].s << " " << sum<<endl;
    for (int i = 0; i < sum; i++)
        cout << xs[i].id << " " << xs[i].s << endl;
    return 0;
}
