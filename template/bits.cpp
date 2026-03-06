#include <bits/stdc++.h>
using namespace std;
void printbits(int n)
{
    for (int i = 63; i >= 0;i--)
    {
        cout << ((n&1l<<i)==0?0:1);
    }
}
int main()
{
    long long n = 9999999999;
    printbits(n);
}
