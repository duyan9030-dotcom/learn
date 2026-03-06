#include <bits/stdc++.h>
using namespace std;
struct node
{
    int winidx;
    int winval;
    int runneridx;
    int runnerval;
};
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int m = 1 << n;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    vector<node> seg(2 * m);
    for (int i = 0; i < m; i++)
    {
        seg[m + i].winidx = i;
        seg[m + i].winval = a[i];
        seg[m + i].runneridx = -1;
        seg[m + i].runnerval = INT_MIN;
    }
    auto combine = [](const node &L, const node &R)
    {
        node p;
        if (L.winval > R.winval)
        {
            p.winidx = L.winidx;
            p.winval = L.winval;
            if (L.runnerval > R.winval)
            {
                p.runneridx = L.runneridx;
                p.runnerval = L.runnerval;
            }
            else
            {
                p.runneridx = R.winidx;
                p.runnerval = R.winval;
            }
        }
        else
        {
            p.winidx = R.winidx;
            p.winval = R.winval;
            if (R.runnerval > L.winval)
            {
                p.runneridx = R.runneridx;
                p.runnerval = R.runnerval;
            }
            else
            {
                p.runneridx = L.winidx;
                p.runnerval = L.winval;
            }
        }

        return p;
    };
    for (int i = m - 1; i >= 1; --i)
    {
        seg[i] = combine(seg[i << 1], seg[i << 1 | 1]);
    }
    int ans = seg[1].runneridx;
    cout << ans + 1;
}