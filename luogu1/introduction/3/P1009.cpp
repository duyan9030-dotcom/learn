#include <bits/stdc++.h>
using namespace std;
// 50!太大，需要高精度乘法和加法
int main()
{
    int n;
    cin >> n;
    int A[1005] = {0}, B[1005] = {0}, i, j;
    A[0] = B[0] = 1;
    for (i = 2; i <= n; i++)
    {
        for (j = 0; j < 100; j++)
            B[j] *= i;//相乘
        for (j = 0; j < 100; j++)//进位
            if (B[j] > 9)
            {
                B[j + 1] += B[j] / 10;
                B[j] %= 10;
            }
        for (j = 0; j < 100; j++)//相加
        {
            A[j] += B[j];
            if (A[j] > 9)
            {
                A[j + 1] += A[j] / 10;
                A[j] %= 10;
            }
        }
    }
    for (i = 100; i >= 0 && A[i] == 0; i--);
    for (j = i; j >= 0; j--)
        cout << A[j];

    return 0;
}
