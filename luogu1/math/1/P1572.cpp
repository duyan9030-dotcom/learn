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
    int ans1, ans2, t1, t2;
    char c1, c2;
    cin >> ans1 >> c1 >> ans2;
    while (cin >> c2)
    {
        cin >> t1 >> c1 >> t2;
        if (c2 == '+')
        {
            ans1 = (ans1 * t2) + t1 * ans2;
            ans2 = ans2 * t2;
        }
        else
        {
            ans1 = (ans1 * t2) - t1 * ans2;
            ans2 = ans2 * t2;
        }
        int g = gcd(abs(ans1), abs(ans2));
        ans1 /= g, ans2 /= g;
    }
    int g = gcd(abs(ans1), abs(ans2));
    ans1 /= g, ans2 /= g;
    if (ans1 == 0) // 0
    {
        cout << 0;
    }
    else if (ans1 % ans2 == 0) // 整数
    {
        cout << ans1 / ans2;
    }
    else if ((ans1 < 0 || ans2 < 0) && !(ans1 < 0 && ans2 < 0))
    {
        cout << "-" << abs(ans1) << "/" << abs(ans2);
    }
    else
    {
        cout << ans1 << "/" << ans2;
    }
}