#include <bits/stdc++.h>
using namespace std;
int n = 0;
bool a[15][15], b[15][15], c[15][15];//原矩阵//目标矩阵//中间矩阵
bool compare() // 检查是否相等
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (b[i][j] !=c[i][j])
                return false;
        }
    }
    return true;
}
void one() // 顺时针转90
{
    bool tmp[15][15] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmp[j][n - 1 - i] = c[i][j];
        }
    }
    memcpy(c, tmp, sizeof(tmp));
}
void four() // 反射
{
    bool tmp[15][15] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tmp[i][n - 1 - j] = c[i][j];
    memcpy(c, tmp, sizeof(tmp));
}
int main()
{
    cin >> n;
    char x;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            a[i][j] = (x == '@');
            c[i][j] = a[i][j];
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            b[i][j] = (x == '@');
        }
    for (int k = 1; k <= 3; k++)
    {
        one();
        if (compare())
        {
            cout << k;
            return 0;
        }
    }
    memcpy(c, a, sizeof(a));
    four();
    if(compare())
    {
        cout << 4;
        return 0;
    }
    for (int k = 1; k <= 3;k++)
    {
        one();
        if(compare())
        {
            cout << 5;
            return 0;
        }
    }
    memcpy(c, a, sizeof(a));
    if(compare())
    {
        cout << 6;
        return 0;
    }
    cout << 7;
    return 0;
}