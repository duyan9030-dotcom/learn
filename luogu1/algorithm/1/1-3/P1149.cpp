#include <bits/stdc++.h>
using namespace std;
int num[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[2005];
int main()
{
    int n, sum = 0;
    cin >> n;
    a[0] = 6;
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = i;j!=0; j /= 10)
        {
            a[i] += num[j % 10];
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (a[j] + a[i] + a[j + i] + 4 == n)
                sum++;
        }
    }
    cout << sum;
    return 0;
}