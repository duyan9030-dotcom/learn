#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pa(m);
    for (int i = 0; i < m; i++)
        cin >> pa[i].first >> pa[i].second;
    sort(pa.begin(), pa.end(), cmp);
    long long sum = 0;
    for (int i = 0; i < m && n > 0; i++)
    {
        sum += n >= pa[i].second ? pa[i].first * pa[i].second : n * pa[i].first;
        n -= pa[i].second;
    }
    cout << sum;
}