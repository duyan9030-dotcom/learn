#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p, l, r, v;
    cin >> n >> p;
    vector<int> a(n + 1);
    vector<int> d(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
    }
    while (p--)
    {
        cin >> l >> r >> v;
        d[l] += v;
        d[r + 1] -= v;
    }
    int ans = 1e9;
    for (int i = 1; i <= n;i++)
    {
        a[i] = a[i - 1] + d[i];
        ans = min(ans, a[i]);
    }
    cout << ans;
    return 0;
}