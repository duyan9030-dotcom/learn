#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
#define pii pair<int, int>
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> ab(n);
    for (int i = 0; i < n; i++)
        cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end(), [](pii a, pii b)
         { return a.first < b.first; }); // 需要枚举起点
    int ans = 0;
    int start = ab[0].first;
    int end = ab[0].second;
    for (int i = 1; i < n; i++)
    {
        if(ab[i].first<=end)
        {
            end = max(end, ab[i].second);
        }
        else{
            ans += end - start;
            start = ab[i].first;
            end = ab[i].second;
        }
    }
    ans += end - start;
    cout << ans;
}