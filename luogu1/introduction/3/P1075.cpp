#include <bits/stdc++.h>
using namespace std;
// 唯一分解定理:任何一个大于 1 的整数，都可以表示为若干个质数的乘积，并且这种分解是唯一的
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i < n;i++)
    {
        if(n%i==0)
        {
            cout <<i;
        }
    }
        return 0;
}