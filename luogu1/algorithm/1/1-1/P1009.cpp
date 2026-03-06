#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int s1[105] = {0}, s2[105] = {0};
    s1[0] = 1, s2[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 100; j++)
            s2[j] *= i;
            
        for (int j = 0; j < 100; j++)
            if (s2[j] >= 10)
            {
                s2[j + 1] += s2[j] / 10;
                s2[j] %= 10;
            }
        for (int j = 0; j < 100; j++)
        {
            s1[j] += s2[j];
            if (s1[j] >= 10)
            {
                s1[j + 1] += s1[j] / 10;
                s1[j] %= 10;
            }
        }
    }
    int head = 99;
    while (s1[head] == 0)
        head--;
    for (; head >= 0; head--)
        cout << s1[head];
    return 0;
}