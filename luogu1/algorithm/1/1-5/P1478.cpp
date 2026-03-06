#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main()
{
    int n, s, a, b, sum = 0;
    cin >> n >> s >> a >> b;
    vector<pair<int, int>> xy(n);
    for (int i = 0; i < n; i++)
        cin >> xy[i].first >> xy[i].second;
    sort(xy.begin(), xy.end(), cmp);
    for (int i = 0; i < n && s >= 0; i++)
    {
        if (a + b >= xy[i].first && s >= xy[i].second)
        {
            sum++;
            s -= xy[i].second;
        }
    }
    cout << sum;
}