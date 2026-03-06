#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b;
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    long double golden = (sqrt((long double)5.0) + 1.0) / 2.0;
    if (a != (ll)((long double)(b - a) * golden+1e-9))
        cout << 1;
    else
        cout << 0;
}