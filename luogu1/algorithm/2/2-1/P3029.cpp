#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pii> xid(n);
    map<int, bool> m;
    for (int i = 0; i < n; i++)
    {
        cin >> xid[i].first >> xid[i].second;
        m[xid[i].second] = 1;
    }
    sort(xid.begin(), xid.end(), [](pii a, pii b)
         { return a.first < b.first; });
    int pz = m.size();
    int ans = 1e9;
    map<int, int> win;
    int cur = 0;
    for (int l=0,r=0; l < n; l++)
    {
        while(cur<pz&&r<n)
        {
            if(win[xid[r].second]==0)
                cur++;
            win[xid[r].second]++;
            r++;
        }
        if(cur==pz)
            ans = min(ans, xid[r-1].first - xid[l].first);
        win[xid[l].second]--;
        if(win[xid[l].second]==0)
            cur--;
    }
    cout<<ans;
}