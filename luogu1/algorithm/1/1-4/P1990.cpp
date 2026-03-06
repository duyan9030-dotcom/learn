#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> sum(n + 1);
    sum[1] = 1;
    sum[2] = 2;
    sum[3] = 5;
    for (int i = 4; i <= n;i++)
    {
        sum[i] =2*sum[i-1]+sum[i-3];
        sum[i] %= 10000;
    }
    cout << sum[n];
}