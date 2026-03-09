#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    ll ans = 0;
    while(x>0&&y>0)
    {
        if(x<y)
            swap(x, y);
        ans += (x / y) * 4 * y;
        x %= y;
    }
    cout << ans;
}