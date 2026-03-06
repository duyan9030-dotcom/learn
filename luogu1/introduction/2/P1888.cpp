#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    cout << a[0] / __gcd(a[0], a[2]) << "/" << a[2] / __gcd(a[0], a[2]);//__gcd(a,b)用于求两数最大公约数
    return 0;
}