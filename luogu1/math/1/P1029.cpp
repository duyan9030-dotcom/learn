#include <bits/stdc++.h>
using namespace std;
typedef __int128 int128;
#define ll long long
const int mod = 1e9 + 7;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y, cnt = 0;
    cin >> x >> y;
    for (int i = x; i <= y; i += x)
    {
        double cur = (x * y) / i;

        if ((i * cur) / x == y && gcd(cur, i) == x)
        {
            cnt++;
        }
    }
    cout << cnt;
}