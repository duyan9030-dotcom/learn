#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,t, s;
    cin >> m >> t >> s;
    if (t == 0)//如果吃掉一个苹果要0min,则必吃完输出0
        {
            cout << 0;
            return 0;
        }
    if((s%t)==0)//如果s是t的整数倍，则吃掉了s/t个苹果
        cout << max(m - s/t,0);
    else
    {
        cout << max(m - s / t - 1, 0);//若不是整数倍则输出m-s/t-1
    }
    return 0;
}