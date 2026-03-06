#include <bits/stdc++.h>
using namespace std;
int h[45][45], N;
int main()
{
    cin >> N;
    int a = 1, b = N / 2 + 1;
    for (int i = 1; i <= N * N; i++)
    {
        h[a][b] = i;
        if ((a == 1 && b == N) || h[a - 1][b + 1] != 0) // 在第一行最后一列，并且右上角无数字
                                                        // 若右上角有数字则不可能在第一行最后一列，两条件不可能同时满足
            // 如果(a == 1 && b == N)==1，放在正下方
            // 如果h[a - 1][b + 1] != 0，即不是第一行也不是第一列并且右上方已经填数，满足条件4
            a++;
        else if (a == 1) // 1
            a = N, b++;
        else if (b == N) // 2
            a--, b = 1;
        else // 条件4的第一种情况
            a--, b++;
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cout << h[i][j] << " ";
        cout << endl;
    }
    return 0;
}
