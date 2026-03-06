#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    map<int, priority_queue<int, vector<int>, greater<int>>> mp;
    for (int &x : a)
    {
        if (mp[x - 1].empty())
            mp[x].push(1);
        else
        {
            int len = mp[x - 1].top();
            mp[x - 1].pop();
            mp[x].push(len + 1);
        }
    }
    int ans = INT_MAX;
    for (auto &pair : mp)
        if (!pair.second.empty())
            ans = min(ans, pair.second.top());
    cout << ans;
    return 0;
}