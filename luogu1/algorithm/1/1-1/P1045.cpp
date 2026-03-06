#include <bits/stdc++.h>
using namespace std;
unsigned long long x[1000] = {0, 1}, t;
int main()
{
    int P;
    cin >> P;
    cout << (int)(P * log10(2) + 1)<<endl;
    for (; P >= 0; P -= 60)
    {
        t = 0;
        for (int j = 1; j <= 500; j++)
        {
            if (P >= 60)
                x[j] <<= 60;
            else
                x[j] <<= P;
            x[j] += t;
            t = x[j] / 10;
            x[j] %= 10;
        }
    }
    x[1] -= 1;
    for (int i = 500; i >= 1; i--)
    {
        cout << x[i];
        if (i % 50 == 1)
            cout << endl;
    }
    return 0;
}