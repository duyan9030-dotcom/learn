#include <bits/stdc++.h>
using namespace std;
int s[5], sum = 0,c[5][25],mark[5] = {0, 1200, 1200, 1200, 1200};
void f(int left, int right, int step, int i)//枚举每个科目题目时间的所有组合
{
    if (step == s[i])
    {
        int tmp = max(left, right);
        if (tmp < mark[i])
            mark[i] = tmp;
        return;
    }
    step++;
    f(c[i][step] + left, right, step, i);
    f(left, c[i][step] + right, step, i);
}
int main()
{
    cin >> s[1] >> s[2] >> s[3] >> s[4];
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= s[i]; j++)
            cin >> c[i][j];
    for (int i = 1; i <= 4; i++)
        f(0, 0, 0, i);
    for (int i = 1; i <= 4; i++)
        sum += mark[i];
    cout << sum;
}