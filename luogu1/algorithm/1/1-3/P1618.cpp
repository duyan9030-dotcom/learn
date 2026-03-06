#include <bits/stdc++.h>
using namespace std;
int main()
{
    int vis[10];
    int a, b, c, l, ans = 0;
    cin >> a >> b >> c;
    int A, B, C;
    for (int k = 1; k <= 1000; k++)
    {
        A = k * a; // 求出三个数
        B = k * b;
        C = k * c;
        if (B > 999 || C > 999) // 判断
            break;
        for (int i = 1; i <= 3; i++) // 标记1-9的vis数组
        {
            vis[A % 10]++;
            A /= 10;
        }
        for (int i = 1; i <= 3; i++)
        {
            vis[B % 10]++;
            B /= 10;
        }
        for (int i = 1; i <= 3; i++)
        {
            vis[C % 10]++;
            C /= 10;
        }
        for (int i = 1; i <= 9; i++)
            if (vis[i] != 1) // 如果有1个0就退出，1-9应该是1
            {
                l = 1; // 标记
                break;
            }
        for (int i = 1; i <= 9; i++)
            vis[i] = 0; // 置0
        if (!l)
        {
            cout << k * a << " " << k * b << " " << k * c << endl;
            ans++; // 记录几组数字满足
        }
        else
            l = 0;
    }
    if (!ans)
        cout << "No!!!";
    return 0;
}