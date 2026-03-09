#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
ll a0, a1, b0, b1;
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void solve()
{
    ll cnt = 0;
    cin >> a0 >> a1 >> b0 >> b1;
    for (ll i= 1; i * i <= b1; i++)
    {
        if (b1 % i == 0)
        {
            if (__gcd(i, a0) == a1 && b1 == i * b0 / __gcd(i, b0))
                cnt++;
            if (i != b1 / i)
            {
                if (__gcd(b1 / i, a0) == a1 && b1 == (b1 / i) * b0 / __gcd(b1 / i, b0))
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        solve();
}