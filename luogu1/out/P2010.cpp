#include <bits/stdc++.h>
using namespace std;
const int mon[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 每年只有365天，闰年的回文日期必是92200229
// 可以直接枚举每一天的回文日期比较
// 年份可以由月份和日期轻易求出来
int main()
{
    int x = 0, y = 0;
    int start = 0, end = 0;
    cin >> start >> end;
    int ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= mon[i]; j++)
        {
            x = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + i / 10;
            y = x * 10000 + i * 100 + j;
            if (y >= start && y <= end)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}