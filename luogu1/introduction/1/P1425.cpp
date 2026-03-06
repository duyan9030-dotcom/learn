#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int m1 = a * 60 + b, m2 = c * 60 + d;
    int x = (m2 - m1) / 60;
    cout << x << " " << (m2 - m1) - x * 60;
    return 0;
}