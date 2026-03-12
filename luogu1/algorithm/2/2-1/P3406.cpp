#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, mp = -1;
    cin >> n >> m;
    vector<ll> p(m);
    for (ll &x : p)
    {
        cin >> x;
        mp = max(mp, x);
    }
    vector<ll> cnt(n + 1); // 差分数组，统计段铁路通过的次数
    for (int i = 1; i < m; i++)
    {
        ll l = min(p[i], p[i - 1]);
        ll r = max(p[i], p[i - 1]);
        cnt[l]++, cnt[r]--;
    }
    for (int i = 1; i <= mp; i++)
        cnt[i] += cnt[i - 1];
    vector<ll> a(n), b(n), c(n);
    for (int i = 1; i < n; i++)
        cin >> a[i] >> b[i] >> c[i];
    ll ans = 0;
    for (int i = 1; i < n; i++)
        ans += min(cnt[i] * a[i], c[i] + b[i] * cnt[i]);
    cout << ans;
}