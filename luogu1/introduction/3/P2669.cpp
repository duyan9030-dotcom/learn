#include <bits/stdc++.h>
using namespace std;
int sum(int n)
{
    int sum = 0;
    for (int i = 1; i <= n;i++)
        sum += i;
    return sum;
}
int main()
{
    int k;
    cin >> k;
    int m = 1;//每天金币数
    int s = 0;//总金币
    for (int i = 1; i <= k;i++)
    {
        if (i > sum(m))
        {
            m++;
        }
        s += m;
        
    }
    cout << s;
    return 0;
}