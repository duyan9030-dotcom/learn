#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int e[100]={0};
    int m = 0;
    for (int i = 1; i <= s1;i++)
    {
        for (int j = 1; j <= s2;j++)
        {
            for (int k = 1; k <= s3;k++)
            {
                e[i + j + k]++;
            }
        }
    }
    for (int i = 3; i <= s1 + s2 + s3;i++)
        m = max(m, e[i]);
    for (int i = 3; i <= s1 + s2 + s3; i++)
        if(m==e[i])
        {
            cout << i;
            return 0;
        }
    return 0;
}