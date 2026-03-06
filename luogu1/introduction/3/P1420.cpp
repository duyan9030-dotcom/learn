#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, a; // x：新输入的数  a:前一个数
    cin >> n >> a;
    int l = 1, s = 1; // l为最大长度,s为当前长度
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        if (x - a == 1) // 只需要判断两数之差进行取舍
        {
            s++;
        }
        else
        {
            s = 1;
        }
        l = max(l, s);
        a = x; // 更新前一个数
    }
    cout << l;
    return 0;
}