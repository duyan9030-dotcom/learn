#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    int l = (n / 7) * 1250;
    for (int i = 0; i < n % 7; i++)
    {
        if (x != 6 && x != 7)
            l += 250;
        if(x==7)
            x = 1;
        else
            x++;
    }
    cout << l;
    return 0;
}