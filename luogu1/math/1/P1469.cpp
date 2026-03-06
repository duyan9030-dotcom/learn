#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a,xorsum=0;
    cin >> n;
    while (n--)
    {
        cin >> a;
        xorsum ^= a;
    }
    cout << xorsum;
}