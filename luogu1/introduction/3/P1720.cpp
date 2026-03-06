#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long f[50] = {0, 1, 1, 2, 3, 5, 8};//把数值开大，不然容易溢出
    for (int i = 6; i < 50; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n] << ".00";
    return 0;
}