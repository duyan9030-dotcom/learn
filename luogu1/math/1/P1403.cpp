#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int f[1000005];
void build()
{
    f[1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        f[i]++;
        int start = i;
        for (int j = start; j <= 1000000; j += i)
        {
            f[j]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    build();
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        ans += f[i];
    cout << ans;
}