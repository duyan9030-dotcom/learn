#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
struct rect
{
    int x1, y1, x2, y2;
};
bool g[2005][2005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<rect> rs(n);
    vector<int> x, y;
    for (rect &a : rs)
    {
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
        x.push_back(a.x1);
        x.push_back(a.x2);
        y.push_back(a.y1);
        y.push_back(a.y2);
    }
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    sort(y.begin(), y.end());
    y.erase(unique(y.begin(), y.end()), y.end());
    auto getx = [&](int &a)
    {
        return lower_bound(x.begin(), x.end(), a) - x.begin();
    };
    auto gety = [&](int &a)
    {
        return lower_bound(y.begin(), y.end(), a) - y.begin();
    };
    for (rect a:rs)
    {
        int xl = min(a.x1, a.x2);
        int xh = max(a.x1, a.x2);
        int yl = min(a.y1, a.y2);
        int yh = max(a.y1, a.y2);
        int xs = getx(xl);
        int xe = getx(xh);
        int ys = gety(yl);
        int ye = gety(yh);
        for (int r = xs; r < xe; r++)
            for (int c = ys; c < ye; c++)
                g[r][c] = true;
    }
    ll ans = 0;
    for (int i = 0; i < x.size() - 1; i++)
        for (int j = 0; j < y.size() - 1; j++)
            if (g[i][j])
                ans += (ll)(x[i + 1] - x[i]) * (y[j + 1] - y[j]);
    cout << ans;
}