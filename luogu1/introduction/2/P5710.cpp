#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin >> m;
    bool p1 = (m % 2)==0;//如果直接p1=m%2,则单数为1，偶数为0
    bool p2 = m > 4 && m <= 12;
    cout << (p1 && p2) << " " << (p1 || p2) << " " << (p1 ^ p2) << " " << (!(p1 || p2));
    return 0;
}