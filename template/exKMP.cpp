#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
int z[20000001];
int e[20000001];
void zarr(string &s, int n)
{
    z[0] = n;
    for (int i = 1, c = 1, r = 1, len; i < n; i++)
    {
        len = r > i ? min(r - i, z[i - c]) : 0;
        while (i + len < n && s[i + len] == s[len])
            len++;
        if (i + len > r)
        {
            r = i + len;
            c = i;
        }
        z[i] = len;
    }
}
void earr(string &a, string &b, int n, int m)
{
    for (int i = 0, c = 0, r = 0, len; i < n; i++)
    {
        len = r > i ? min(r - i, z[i - c]) : 0;
        while (i + len < n && len < m && a[i + len] == b[len])
            len++;
        if (i + len > r)
        {
            r = i + len;
            c = i;
        }
        e[i] = len;
    }
}
ll eor(int arr[], int n)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans ^= 1LL * (i + 1) * (arr[i] + 1);
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    zarr(b, b.length());
    earr(a, b, a.length(), b.length());
    cout << eor(z, b.length()) << '\n'
         << eor(e, a.length());
}