#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    int a, base;
    cin >> a >> base;
    cout << a << "=";
    if (a == 0)
    {
        cout << "0(base" << base << ")" << endl;
        return 0;
    }
    string ans = "";
    while (a != 0)
    {
        int cur = a % base;
        a /= base;
        if (cur < 0)
            cur -= base, a++;
        ans += ((cur <= 9) ? cur + '0' : cur - 10 + 'A');
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
    cout << "(base" << base << ")";
}