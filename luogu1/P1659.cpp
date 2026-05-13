#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 19930726;
ll p[2000005];
ll cnt[2000005];
ll n, k;
ll power(ll a, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        p >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    string s, ss = "#";
    cin >> s;
    for (char c : s)
    {
        ss += c;
        ss += '#';
    }
    for (ll i = 0, r = 0, c = 0, len; i < ss.size(); i++)
    {
        len = r > i ? min(p[2 * c - i], r - i) : 1;
        while (i + len < ss.size() && i - len >= 0 && ss[i + len] == ss[i - len])
            len++;
        if (i + len > r)
        {
            r = i + len;
            c = i;
        }
        p[i] = len;
        // cout << p[i] << " ";
    }
    for (int i = 1; i < ss.size(); i += 2)
        cnt[p[i] - 1]++;
    ll ans = 1;
    ll sum = 0;
    // cout << endl
    //      << n << " " << k;
    for (int len = ss.size() - 2; len > 0 && k > 0; len -= 2)
    {
        sum += cnt[len];
        ans = (ans * power(len, min(k, sum))) % mod;
        k -= sum;
    }
    cout << (k > 0 ? -1 : ans);
}