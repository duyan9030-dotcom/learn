#include <bits/stdc++.h>
using namespace std;
int tao(int n)
{
    if(n==1)
        return 1;
    return (1 + tao(n - 1)) * 2;
}
int main()
{
    int n;
    cin >> n;
    cout << tao(n);
    return 0;
}
